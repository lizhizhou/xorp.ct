// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/mld6igmp/mld6igmp_node.cc,v 1.15 2003/10/14 22:39:46 pavlin Exp $"


//
// Multicast Listener Discovery and Internet Group Management Protocol
// node implementation (common part).
// MLDv1 (RFC 2710), IGMPv1 and IGMPv2 (RFC 2236).
//


#include "mld6igmp_module.h"
#include "mld6igmp_private.hh"
#include "mld6igmp_node.hh"
#include "mld6igmp_vif.hh"



//
// Exported variables
//

//
// Local constants definitions
//

//
// Local structures/classes, typedefs and macros
//


//
// Local variables
//

//
// Local functions prototypes
//


/**
 * Mld6igmpNode::Mld6igmpNode:
 * @family: The address family (%AF_INET or %AF_INET6
 * for IPv4 and IPv6 respectively).
 * @module_id: The module ID (must be %XORP_MODULE_MLD6IGMP).
 * @eventloop: The event loop.
 * 
 * MLD6IGMP node constructor.
 **/
Mld6igmpNode::Mld6igmpNode(int family, xorp_module_id module_id,
			   EventLoop& eventloop)
    : ProtoNode<Mld6igmpVif>(family, module_id, eventloop),
    _is_log_trace(true)			// XXX: default to print trace logs
{
    XLOG_ASSERT(module_id == XORP_MODULE_MLD6IGMP);
    if (module_id != XORP_MODULE_MLD6IGMP) {
	XLOG_FATAL("Invalid module ID = %d (must be 'XORP_MODULE_MLD6IGMP' = %d)",
		   module_id, XORP_MODULE_MLD6IGMP);
    }
    
    _buffer_recv = BUFFER_MALLOC(BUF_SIZE_DEFAULT);
    
    //
    // Set the node status.
    // XXX: note that we don't really need to wait for MFEA,
    // hence we are READY.
    //
    ProtoNode<Mld6igmpVif>::set_node_status(PROC_READY);
}

/**
 * Mld6igmpNode::~Mld6igmpNode:
 * @: 
 * 
 * MLD6IGMP node destructor.
 * 
 **/
Mld6igmpNode::~Mld6igmpNode()
{
    stop();
    
    delete_all_vifs();
    
    BUFFER_FREE(_buffer_recv);
}

/**
 * Mld6igmpNode::start:
 * @: 
 * 
 * Start the MLD or IGMP protocol.
 * TODO: This function should not start the protocol operation on the
 * interfaces. The interfaces must be activated separately.
 * 
 * Return value: %XORP_OK on success, otherwize %XORP_ERROR.
 **/
int
Mld6igmpNode::start()
{
    if (ProtoNode<Mld6igmpVif>::start() < 0)
	return (XORP_ERROR);
    
    //
    // Set the node status.
    // XXX: note that we don't really need to wait for MFEA,
    // hence we are READY.
    //
    ProtoNode<Mld6igmpVif>::set_node_status(PROC_READY);
    
    //
    // Start the protocol with the kernel
    //
    if (start_protocol_kernel() != XORP_OK) {
	XLOG_ERROR("Error starting protocol with the kernel");
	ProtoNode<Mld6igmpVif>::stop();
	return (XORP_ERROR);
    }
    
    // Start the mld6igmp_vifs
    start_all_vifs();
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::stop:
 * @: 
 * 
 * Stop the MLD or IGMP protocol.
 * XXX: This function, unlike start(), will stop the protocol
 * operation on all interfaces.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::stop()
{
    if (! is_up())
	return (XORP_ERROR);
    
    //
    // Perform misc. MLD6IGMP-specific stop operations
    //
    // XXX: nothing to do
    
    // Stop the vifs
    stop_all_vifs();
    
    //
    // Stop the protocol with the kernel
    //
    if (stop_protocol_kernel() != XORP_OK) {
	XLOG_ERROR("Error stopping protocol with the kernel. Ignored.");
    }
    
    // XXX: don't change the node status, because we are still ready
    
    if (ProtoNode<Mld6igmpVif>::stop() < 0)
	return (XORP_ERROR);
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::is_waiting_for_mfea_startup:
 * @: 
 * 
 * Test if waiting to complete registration with the MFEA.
 * 
 * Return value: True if waiting to complete registration with the MFEA,
 * otherwise false.
 **/
bool
Mld6igmpNode::is_waiting_for_mfea_startup() const
{
    return (_waiting_for_mfea_startup_events != 0);
}

void
Mld6igmpNode::incr_waiting_for_mfea_startup_events()
{
    _waiting_for_mfea_startup_events++;
}

void
Mld6igmpNode::decr_waiting_for_mfea_startup_events()
{
    XLOG_ASSERT(_waiting_for_mfea_startup_events > 0);
    _waiting_for_mfea_startup_events--;
    
    if (_waiting_for_mfea_startup_events == 0) {
	// If startup waiting is over, set node status to NOT_READY
	if (ProtoNode<Mld6igmpVif>::node_status() == PROC_STARTUP)
	    ProtoNode<Mld6igmpVif>::set_node_status(PROC_NOT_READY);
    }
}

/**
 * Mld6igmpNode::has_pending_down_units:
 * @reason_msg: return-by-reference string that contains human-readable
 * information about the status.
 * 
 * Test if there is an unit that is in PENDING_DOWN state.
 * 
 * Return value: True if there is an unit that is in PENDING_DOWN state,
 * otherwise false.
 **/
bool
Mld6igmpNode::has_pending_down_units(string& reason_msg)
{
    vector<Mld6igmpVif *>::iterator iter;
    
    //
    // Test the interfaces
    //
    for (iter = proto_vifs().begin(); iter != proto_vifs().end(); ++iter) {
	Mld6igmpVif *mld6igmp_vif = (*iter);
	if (mld6igmp_vif == NULL)
	    continue;
	// TODO: XXX: PAVPAVPAV: vif pending-down state
	// is not used/implemented yet
	if (mld6igmp_vif->is_pending_down()) {
	    reason_msg = c_format("Vif %s is in state %s",
				  mld6igmp_vif->name().c_str(),
				  mld6igmp_vif->state_string());
	    return (true);
	}
    }
    
    //
    // TODO: XXX: PAVPAVPAV: test other units that may be waiting
    // in PENDING_DOWN state.
    //
    
    reason_msg = "No pending-down units";
    return (false);
}

/**
 * Mld6igmpNode::node_status:
 * @reason_msg: return-by-reference string that contains human-readable
 * information about the status.
 * 
 * Get the node status (see @ref ProcessStatus).
 * 
 * Return value: The node status (see @ref ProcessStatus).
 **/
ProcessStatus
Mld6igmpNode::node_status(string& reason_msg)
{
    ProcessStatus status = ProtoNode<Mld6igmpVif>::node_status();
    
    // Set the return message with the reason
    reason_msg = "";
    switch (status) {
    case PROC_NULL:
	// Can't be running and in this state
	XLOG_UNREACHABLE();
	break;
    case PROC_STARTUP:
	if (is_waiting_for_mfea_startup()) {
	    reason_msg = "Waiting for MFEA startup";
	    break;
	}
	// Waiting for unknown reason
	XLOG_UNREACHABLE();
	break;
    case PROC_NOT_READY:
	// TODO: XXX: PAVPAVPAV: when can we be in this stage?
	XLOG_UNFINISHED();
	break;
    case PROC_READY:
	reason_msg = c_format("Node is READY (running status %s)",
			      ProtoState::state_string());
	break;
    case PROC_SHUTDOWN:
	// Get the message about the shutdown progress
	has_pending_down_units(reason_msg);
	break;
    case PROC_FAILED:
	// TODO: XXX: PAVPAVPAV: when can we be in this stage?
	XLOG_UNFINISHED();
	break;
    default:
	// Unknown status
	XLOG_UNREACHABLE();
	break;
    }
    
    return (status);
}

/**
 * Mld6igmpNode::add_vif:
 * @vif: Information about the new Mld6igmpVif to install.
 * @error_msg: The error message (if error).
 * 
 * Install a new MLD/IGMP vif.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::add_vif(const Vif& vif, string& error_msg)
{
    //
    // Create a new Mld6igmpVif
    //
    Mld6igmpVif *mld6igmp_vif = new Mld6igmpVif(*this, vif);
    
    if (ProtoNode<Mld6igmpVif>::add_vif(mld6igmp_vif) != XORP_OK) {
	// Cannot add this new vif
	error_msg = c_format("Cannot add vif %s: internal error",
			     vif.name().c_str());
	XLOG_ERROR(error_msg.c_str());
	
	delete mld6igmp_vif;
	return (XORP_ERROR);
    }
    
    XLOG_INFO("New vif: %s", mld6igmp_vif->str().c_str());
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::add_vif:
 * @vif_name: The name of the new vif.
 * @vif_index: The vif index of the new vif.
 * @error_msg: The error message (if error).
 * 
 * Install a new MLD/IGMP vif. If the vif exists, nothing is installed.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::add_vif(const string& vif_name, uint32_t vif_index,
		      string& error_msg)
{
    Mld6igmpVif *mld6igmp_vif = vif_find_by_vif_index(vif_index);
    
    if ((mld6igmp_vif != NULL) && (mld6igmp_vif->name() == vif_name)) {
	return (XORP_OK);		// Already have this vif
    }
    
    //
    // Create a new Vif
    //
    Vif vif(vif_name);
    vif.set_vif_index(vif_index);
    if (add_vif(vif, error_msg) != XORP_OK) {
	return (XORP_ERROR);
    }
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::delete_vif:
 * @vif_name: The name of the vif to delete.
 * @error_msg: The error message (if error).
 * 
 * Delete an existing MLD/IGMP vif.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::delete_vif(const string& vif_name, string& error_msg)
{
    Mld6igmpVif *mld6igmp_vif = vif_find_by_name(vif_name);
    if (mld6igmp_vif == NULL) {
	error_msg = c_format("Cannot delete vif %s: no such vif",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    if (ProtoNode<Mld6igmpVif>::delete_vif(mld6igmp_vif) != XORP_OK) {
	error_msg = c_format("Cannot delete vif %s: internal error",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	delete mld6igmp_vif;
	return (XORP_ERROR);
    }
    
    delete mld6igmp_vif;
    
    XLOG_INFO("Deleted vif: %s", vif_name.c_str());
    
    return (XORP_OK);
}

int
Mld6igmpNode::set_vif_flags(const string& vif_name,
			    bool is_pim_register, bool is_p2p,
			    bool is_loopback, bool is_multicast,
			    bool is_broadcast, bool is_up,
			    string& error_msg)
{
    bool is_changed = false;
    
    Mld6igmpVif *mld6igmp_vif = vif_find_by_name(vif_name);
    if (mld6igmp_vif == NULL) {
	error_msg = c_format("Cannot set flags vif %s: no such vif",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    if (mld6igmp_vif->is_pim_register() != is_pim_register) {
	mld6igmp_vif->set_pim_register(is_pim_register);
	is_changed = true;
    }
    if (mld6igmp_vif->is_p2p() != is_p2p) {
	mld6igmp_vif->set_p2p(is_p2p);
	is_changed = true;
    }
    if (mld6igmp_vif->is_loopback() != is_loopback) {
	mld6igmp_vif->set_loopback(is_loopback);
	is_changed = true;
    }
    if (mld6igmp_vif->is_multicast_capable() != is_multicast) {
	mld6igmp_vif->set_multicast_capable(is_multicast);
	is_changed = true;
    }
    if (mld6igmp_vif->is_broadcast_capable() != is_broadcast) {
	mld6igmp_vif->set_broadcast_capable(is_broadcast);
	is_changed = true;
    }
    if (mld6igmp_vif->is_underlying_vif_up() != is_up) {
	mld6igmp_vif->set_underlying_vif_up(is_up);
	is_changed = true;
    }
    
    if (is_changed)
	XLOG_INFO("Vif flags changed: %s", mld6igmp_vif->str().c_str());
    
    return (XORP_OK);
}

int
Mld6igmpNode::add_vif_addr(const string& vif_name,
			   const IPvX& addr,
			   const IPvXNet& subnet_addr,
			   const IPvX& broadcast_addr,
			   const IPvX& peer_addr,
			   string& error_msg)
{
    Mld6igmpVif *mld6igmp_vif = vif_find_by_name(vif_name);
    if (mld6igmp_vif == NULL) {
	error_msg = c_format("Cannot add address on vif %s: no such vif",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    const VifAddr vif_addr(addr, subnet_addr, broadcast_addr, peer_addr);
    
    //
    // Check the arguments
    //
    if (! addr.is_unicast()) {
	error_msg = c_format("Cannot add address on vif %s: "
			     "invalid unicast address: %s",
			     vif_name.c_str(), addr.str().c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    if ((addr.af() != family())
	|| (subnet_addr.af() != family())
	|| (broadcast_addr.af() != family())
	|| (peer_addr.af() != family())) {
	error_msg = c_format("Cannot add address on vif %s: "
			     "invalid address family: %s ",
			     vif_name.c_str(), vif_addr.str().c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    VifAddr* node_vif_addr = mld6igmp_vif->find_address(addr);
    
    if (node_vif_addr != NULL) {
	// Update the address
	if (*node_vif_addr == vif_addr)
	    return (XORP_OK);		// Already have this address
	XLOG_INFO("Updated existing address on vif %s: old is %s new is %s",
		  mld6igmp_vif->name().c_str(), node_vif_addr->str().c_str(),
		  vif_addr.str().c_str());
	*node_vif_addr = vif_addr;
    } else {
	// Add a new address
	mld6igmp_vif->add_address(vif_addr);
	
	XLOG_INFO("Added new address to vif %s: %s",
		  mld6igmp_vif->name().c_str(), vif_addr.str().c_str());
    }
    
    return (XORP_OK);
}

int
Mld6igmpNode::delete_vif_addr(const string& vif_name,
			      const IPvX& addr,
			      string& error_msg)
{
    Mld6igmpVif *mld6igmp_vif = vif_find_by_name(vif_name);
    if (mld6igmp_vif == NULL) {
	error_msg = c_format("Cannot delete address on vif %s: no such vif",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    const VifAddr *tmp_vif_addr = mld6igmp_vif->find_address(addr);
    if (tmp_vif_addr == NULL) {
	error_msg = c_format("Cannot delete address on vif %s: "
			     "invalid address %s",
			     vif_name.c_str(), addr.str().c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    VifAddr vif_addr = *tmp_vif_addr;	// Get a copy
    if (mld6igmp_vif->delete_address(addr) != XORP_OK) {
	XLOG_UNREACHABLE();
	return (XORP_ERROR);
    }
    
    XLOG_INFO("Deleted address on vif %s: %s",
	      mld6igmp_vif->name().c_str(), vif_addr.str().c_str());
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::enable_vif:
 * @vif_name: The name of the vif to enable.
 * @error_msg: The error message (if error).
 * 
 * Enable an existing MLD6IGMP vif.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::enable_vif(const string& vif_name, string& error_msg)
{
    Mld6igmpVif *mld6igmp_vif = vif_find_by_name(vif_name);
    if (mld6igmp_vif == NULL) {
	error_msg = c_format("Cannot enable vif %s: no such vif",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    mld6igmp_vif->enable();
    
    XLOG_INFO("Enabled vif: %s", vif_name.c_str());
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::disable_vif:
 * @vif_name: The name of the vif to disable.
 * @error_msg: The error message (if error).
 * 
 * Disable an existing MLD6IGMP vif.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::disable_vif(const string& vif_name, string& error_msg)
{
    Mld6igmpVif *mld6igmp_vif = vif_find_by_name(vif_name);
    if (mld6igmp_vif == NULL) {
	error_msg = c_format("Cannot disable vif %s: no such vif",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    mld6igmp_vif->disable();
    
    XLOG_INFO("Disabled vif: %s", vif_name.c_str());
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::start_vif:
 * @vif_name: The name of the vif to start.
 * @error_msg: The error message (if error).
 * 
 * Start an existing MLD6IGMP vif.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::start_vif(const string& vif_name, string& error_msg)
{
    Mld6igmpVif *mld6igmp_vif = vif_find_by_name(vif_name);
    if (mld6igmp_vif == NULL) {
	error_msg = c_format("Cannot start vif %s: no such vif",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    if (mld6igmp_vif->start() != XORP_OK) {
	error_msg = c_format("Cannot start vif %s: internal error",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    XLOG_INFO("Started vif: %s", vif_name.c_str());
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::stop_vif:
 * @vif_name: The name of the vif to stop.
 * @error_msg: The error message (if error).
 * 
 * Stop an existing MLD6IGMP vif.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::stop_vif(const string& vif_name, string& error_msg)
{
    Mld6igmpVif *mld6igmp_vif = vif_find_by_name(vif_name);
    if (mld6igmp_vif == NULL) {
	error_msg = c_format("Cannot stop vif %s: no such vif",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    if (mld6igmp_vif->stop() != XORP_OK) {
	error_msg = c_format("Cannot stop vif %s: internal error",
			     vif_name.c_str());
	XLOG_ERROR(error_msg.c_str());
	return (XORP_ERROR);
    }
    
    XLOG_INFO("Stopped vif: %s", vif_name.c_str());
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::start_all_vifs:
 * @: 
 * 
 * Start MLD/IGMP on all enabled interfaces.
 * 
 * Return value: The number of virtual interfaces MLD/IGMP was started on,
 * or %XORP_ERROR if error occured.
 **/
int
Mld6igmpNode::start_all_vifs()
{
    int n = 0;
    vector<Mld6igmpVif *>::iterator iter;
    
    for (iter = proto_vifs().begin(); iter != proto_vifs().end(); ++iter) {
	Mld6igmpVif *mld6igmp_vif = (*iter);
	if (mld6igmp_vif == NULL)
	    continue;
	if (mld6igmp_vif->start() == XORP_OK)
	    n++;
    }
    
    return (n);
}

/**
 * Mld6igmpNode::stop_all_vifs:
 * @: 
 * 
 * Stop MLD/IGMP on all interfaces it was running on.
 * 
 * Return value: The number of virtual interfaces MLD/IGMP was stopped on,
 * or %XORP_ERROR if error occured.
 **/
int
Mld6igmpNode::stop_all_vifs()
{
    int n = 0;
    vector<Mld6igmpVif *>::iterator iter;
    
    for (iter = proto_vifs().begin(); iter != proto_vifs().end(); ++iter) {
	Mld6igmpVif *mld6igmp_vif = (*iter);
	if (mld6igmp_vif == NULL)
	    continue;
	if (mld6igmp_vif->stop() == XORP_OK)
	    n++;
    }
    
    return (n);
}

/**
 * Mld6igmpNode::enable_all_vifs:
 * @: 
 * 
 * Enable MLD/IGMP on all interfaces.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::enable_all_vifs()
{
    vector<Mld6igmpVif *>::iterator iter;
    
    for (iter = proto_vifs().begin(); iter != proto_vifs().end(); ++iter) {
	Mld6igmpVif *mld6igmp_vif = (*iter);
	if (mld6igmp_vif == NULL)
	    continue;
	mld6igmp_vif->enable();
    }
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::disable_all_vifs:
 * @: 
 * 
 * Disable MLD/IGMP on all interfaces. All running interfaces are stopped
 * first.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::disable_all_vifs()
{
    vector<Mld6igmpVif *>::iterator iter;
    
    stop_all_vifs();
    
    for (iter = proto_vifs().begin(); iter != proto_vifs().end(); ++iter) {
	Mld6igmpVif *mld6igmp_vif = (*iter);
	if (mld6igmp_vif == NULL)
	    continue;
	mld6igmp_vif->disable();
    }
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::delete_all_vifs:
 * @: 
 * 
 * Delete all MLD/IGMP vifs.
 **/
void
Mld6igmpNode::delete_all_vifs()
{
    // XXX: here we must use proto_vifs().size() to end the iteration,
    // because the proto_vifs() array may be modified when a vif
    // is deleted.
    for (size_t i = 0; i < proto_vifs().size(); i++) {
	Mld6igmpVif *mld6igmp_vif = vif_find_by_vif_index(i);
	if (mld6igmp_vif == NULL)
	    continue;
	delete mld6igmp_vif;
    }
    
    proto_vifs().clear();
}

/**
 * Mld6igmpNode::proto_recv:
 * @src_module_instance_name: The module instance name of the module-origin
 * of the message.
 * @src_module_id: The #xorp_module_id of the module-origin of the message.
 * @vif_index: The vif index of the interface used to receive this message.
 * @src: The source address of the message.
 * @dst: The destination address of the message.
 * @ip_ttl: The IP TTL of the message. If it has a negative value,
 * it should be ignored.
 * @ip_tos: The IP TOS of the message. If it has a negative value,
 * it should be ignored.
 * @router_alert_bool: If true, the Router Alert IP option for the IP
 * packet of the incoming message was set.
 * @rcvbuf: The data buffer with the received message.
 * @rcvlen: The data length in @rcvbuf.
 * 
 * Receive a protocol message from the kernel.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::proto_recv(const string&	, // src_module_instance_name,
			 xorp_module_id src_module_id,
			 uint16_t vif_index,
			 const IPvX& src, const IPvX& dst,
			 int ip_ttl, int ip_tos, bool router_alert_bool,
			 const uint8_t *rcvbuf, size_t rcvlen)
{
    Mld6igmpVif *mld6igmp_vif = NULL;
    int ret_value = XORP_ERROR;
    
    debug_msg("Received message from %s to %s: "
	      "ip_ttl = %d ip_tos = %#x router_alert = %d rcvlen = %u\n",
	      cstring(src), cstring(dst),
	      ip_ttl, ip_tos, router_alert_bool, (uint32_t)rcvlen);
    
    //
    // Check whether the node is up.
    //
    if (! is_up())
	return (XORP_ERROR);
    
    //
    // Find the vif for that packet
    //
    mld6igmp_vif = vif_find_by_vif_index(vif_index);
    if (mld6igmp_vif == NULL) {
	XLOG_UNREACHABLE();
	return (XORP_ERROR);
    }
    
    // Copy the data to the receiving #buffer_t
    BUFFER_RESET(_buffer_recv);
    BUFFER_PUT_DATA(rcvbuf, _buffer_recv, rcvlen);
    
    // Process the data by the vif
    ret_value = mld6igmp_vif->mld6igmp_recv(src, dst, ip_ttl, ip_tos,
					    router_alert_bool,
					    _buffer_recv);
    
    return (ret_value);
    
 buflen_error:
    XLOG_UNREACHABLE();
    return (XORP_ERROR);
    
    UNUSED(src_module_id);
}

/**
 * Mld6igmpNode::mld6igmp_send:
 * @vif_index: The vif index of the interface to send this message.
 * @src: The source address of the message.
 * @dst: The destination address of the message.
 * @ip_ttl: The IP TTL of the message. If it has a negative value,
 * the TTL will be set by the lower layers.
 * @ip_tos: The IP TOS of the message. If it has a negative value,
 * the TOS will be set by the lower layers.
 * @router_alert_bool: If true, set the Router Alert IP option for the IP
 * packet of the outgoung message.
 * @buffer: The #buffer_t data buffer with the message to send.
 * 
 * Send a MLD or IGMP message.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::mld6igmp_send(uint16_t vif_index,
			    const IPvX& src, const IPvX& dst,
			    int ip_ttl, int ip_tos, bool router_alert_bool,
			    buffer_t *buffer)
{
    if (! is_up())
	return (XORP_ERROR);
    
    // TODO: the target name of the MFEA must be configurable.
    if (proto_send(xorp_module_name(family(), XORP_MODULE_MFEA),
		   XORP_MODULE_MFEA,
		   vif_index, src, dst,
		   ip_ttl, ip_tos, router_alert_bool,
		   BUFFER_DATA_HEAD(buffer),
		   BUFFER_DATA_SIZE(buffer)) < 0) {
	return (XORP_ERROR);
    }
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::add_protocol:
 * @module_instance_name: The module instance name of the protocol to add.
 * @module_id: The #xorp_module_id of the protocol to add.
 * @vif_index: The vif index of the interface to add the protocol to.
 * 
 * Add a protocol to the list of entries that would be notified if there
 * is membership change on a particular interface.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::add_protocol(const string& module_instance_name,
			   xorp_module_id module_id,
			   uint16_t vif_index)
{
    Mld6igmpVif *mld6igmp_vif = vif_find_by_vif_index(vif_index);
    
    if (mld6igmp_vif == NULL) {
	XLOG_ERROR("Cannot add protocol instance %s on vif_index %d: "
		   "no such vif",
		   module_instance_name.c_str(), vif_index);
	return (XORP_ERROR);
    }
    
    if (mld6igmp_vif->add_protocol(module_id, module_instance_name) < 0)
	return (XORP_ERROR);
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::delete_protocol:
 * @module_instance_name: The module instance name of the protocol to delete.
 * @module_id: The #xorp_module_id of the protocol to delete.
 * @vif_index: The vif index of the interface to delete the protocol from.
 * 
 * Delete a protocol from the list of entries that would be notified if there
 * is membership change on a particular interface.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::delete_protocol(const string& module_instance_name,
			      xorp_module_id module_id,
			      uint16_t vif_index)
{
    Mld6igmpVif *mld6igmp_vif = vif_find_by_vif_index(vif_index);
    
    if (mld6igmp_vif == NULL) {
	XLOG_ERROR("Cannot delete protocol instance %s on vif_index %d: "
		   "no such vif",
		   module_instance_name.c_str(), vif_index);
	return (XORP_ERROR);
    }
    
    if (mld6igmp_vif->delete_protocol(module_id, module_instance_name) < 0)
	return (XORP_ERROR);
    
    return (XORP_OK);
}

/**
 * Mld6igmpNode::join_prune_notify_routing:
 * @module_instance_name: The module instance name of the protocol to notify.
 * @module_id: The #xorp_module_id of the protocol to notify.
 * @vif_index: The vif index of the interface with membership change.
 * @source: The source address of the (S,G) or (*,G) entry that has changed.
 * In case of group-specific membership, it is IPvX::ZERO().
 * @group: The group address of the (S,G) or (*,G) entry that has changed.
 * @action_jp: The membership change type #action_jp_t:
 * either %ACTION_JOIN or %ACTION_PRUNE.
 * 
 * Notify the protocol instance with name @module_instance_name that there is
 * multicast membership change on interface with vif index of @vif_index.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
Mld6igmpNode::join_prune_notify_routing(const string& module_instance_name,
					xorp_module_id module_id,
					uint16_t vif_index,
					const IPvX& source,
					const IPvX& group,
					action_jp_t action_jp)
{
    //
    // Send add/delete membership to the registered protocol instance.
    //
    switch (action_jp) {
    case ACTION_JOIN:
	send_add_membership(module_instance_name, module_id,
			    vif_index, source, group);
	break;
    case ACTION_PRUNE:
	send_delete_membership(module_instance_name, module_id, 
			       vif_index, source, group);
	break;
    default:
	XLOG_UNREACHABLE();
	break;
    }
    
    return (XORP_OK);
}
