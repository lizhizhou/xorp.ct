/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/ospf_xif.hh,v 1.10 2002/11/19 19:31:45 hodson Exp $
 */


#ifndef __XRL_INTERFACES_OSPF_XIF_HH__
#define __XRL_INTERFACES_OSPF_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifOspf"
#include "libxorp/xlog.h"
#include "libxipc/xrlrouter.hh"

class XrlOspfV0p1Client {
public:
    XrlOspfV0p1Client(XrlRouter* r) : _router(r) {}
    virtual ~XrlOspfV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB0;
    /**
     *  Send Xrl intended to:
     *  
     *  Set router id
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_router_id(
	const char*	target_name, 
	const uint32_t&	id, 
	const CB0&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB1;
    /**
     *  Send Xrl intended to:
     *  
     *  Get router id
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_get_router_id(
	const char*	target_name, 
	const CB1&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB2;
    /**
     *  Send Xrl intended to:
     *  
     *  Set maximum number of AS-external LSA's
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_lsdb_limit(
	const char*	target_name, 
	const int32_t&	limit, 
	const CB2&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const int32_t*>::RefPtr CB3;

    bool send_get_lsdb_limit(
	const char*	target_name, 
	const CB3&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB4;
    /**
     *  Send Xrl intended to:
     *  
     *  Enable / disable MOSPF
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_mospf(
	const char*	target_name, 
	const bool&	enabled, 
	const CB4&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr CB5;

    bool send_get_mospf(
	const char*	target_name, 
	const CB5&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB6;
    /**
     *  Send Xrl intended to:
     *  
     *  Enable / Disable Inter-area multicast
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_interarea_mc(
	const char*	target_name, 
	const bool&	enabled, 
	const CB6&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr CB7;

    bool send_get_interarea_mc(
	const char*	target_name, 
	const CB7&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB8;
    /**
     *  Send Xrl intended to:
     *  
     *  Set time to exit overflow state
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_overflow_interval(
	const char*	target_name, 
	const int32_t&	ovfl_int, 
	const CB8&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const int32_t*>::RefPtr CB9;

    bool send_get_overflow_interval(
	const char*	target_name, 
	const CB9&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB10;
    /**
     *  Send Xrl intended to:
     *  
     *  Set flood rate - self orig per second
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_flood_rate(
	const char*	target_name, 
	const int32_t&	rate, 
	const CB10&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const int32_t*>::RefPtr CB11;

    bool send_get_flood_rate(
	const char*	target_name, 
	const CB11&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB12;
    /**
     *  Send Xrl intended to:
     *  
     *  Set back-to-back retransmissions
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_max_rxmt_window(
	const char*	target_name, 
	const uint32_t&	window, 
	const CB12&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB13;

    bool send_get_max_rxmt_window(
	const char*	target_name, 
	const CB13&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB14;
    /**
     *  Send Xrl intended to:
     *  
     *  Set maximum simultaneous DB exchanges
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_max_dds(
	const char*	target_name, 
	const uint32_t&	max_dds, 
	const CB14&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB15;

    bool send_get_max_dds(
	const char*	target_name, 
	const CB15&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB16;
    /**
     *  Send Xrl intended to:
     *  
     *  Set rate to refresh DoNotAge LSAs
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_lsa_refresh_rate(
	const char*	target_name, 
	const uint32_t&	rate, 
	const CB16&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB17;

    bool send_get_lsa_refresh_rate(
	const char*	target_name, 
	const CB17&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB18;
    /**
     *  Send Xrl intended to:
     *  
     *  Set the maximum number of point-to-point links that will become
     *  adjacent to a particular neighbor. If there is no limit then value is
     *  zero.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_p2p_adj_limit(
	const char*	target_name, 
	const uint32_t&	max_adj, 
	const CB18&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB19;

    bool send_get_p2p_adj_limit(
	const char*	target_name, 
	const CB19&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB20;
    /**
     *  Send Xrl intended to:
     *  
     *  Set randomized LSA refreshes
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_set_random_refresh(
	const char*	target_name, 
	const bool&	enabled, 
	const CB20&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr CB21;

    bool send_get_random_refresh(
	const char*	target_name, 
	const CB21&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB22;
    /**
     *  Send Xrl intended to:
     *  
     *  Create area
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_add_or_configure_area(
	const char*	target_name, 
	const uint32_t&	area_id, 
	const bool&	is_stub, 
	const uint32_t&	default_cost, 
	const bool&	import_summary_routes, 
	const CB22&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB23;
    /**
     *  Send Xrl intended to:
     *  
     *  Delete area
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_delete_area(
	const char*	target_name, 
	const uint32_t&	area_id, 
	const CB23&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const bool*, const uint32_t*, const bool*>::RefPtr CB24;
    /**
     *  Send Xrl intended to:
     *  
     *  Query area options
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_query_area(
	const char*	target_name, 
	const uint32_t&	area_id, 
	const CB24&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr CB25;
    /**
     *  Send Xrl intended to:
     *  
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_list_area_ids(
	const char*	target_name, 
	const CB25&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB26;
    /**
     *  Send Xrl intended to:
     *  
     *  Add or configure aggregate.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param area_id id of area aggregate belongs to.
     *  
     *  @param network network identifier.
     *  
     *  @param netmask netmask identifier.
     *  
     *  @param suppress_advertisement of aggregate.
     */
    bool send_add_or_configure_aggregate(
	const char*	target_name, 
	const uint32_t&	area_id, 
	const IPv4&	network, 
	const IPv4&	netmask, 
	const bool&	suppress_advertisement, 
	const CB26&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB27;
    /**
     *  Send Xrl intended to:
     *  
     *  Delete aggregate identified by area_id, network, and netmask
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_delete_aggregate(
	const char*	target_name, 
	const uint32_t&	area_id, 
	const IPv4&	network, 
	const IPv4&	netmask, 
	const CB27&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr CB28;
    /**
     *  Send Xrl intended to:
     *  
     *  Query aggregate identified by area_id, network, and netmask
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_query_aggregate(
	const char*	target_name, 
	const uint32_t&	area_id, 
	const IPv4&	network, 
	const IPv4&	netmask, 
	const CB28&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const XrlAtomList*, const XrlAtomList*>::RefPtr CB29;
    /**
     *  Send Xrl intended to:
     *  
     *  Return list of aggregate identifiers for area identified by area_id.
     *  Two lists are returned, the nth elements in each list comprise the
     *  tuple (network,netmask) that uniquely identifies the aggregate within
     *  the area.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_list_aggregates(
	const char*	target_name, 
	const uint32_t&	area_id, 
	const CB29&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB30;
    /**
     *  Send Xrl intended to:
     *  
     *  Add or configure host routes.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param area_id host is to be advertised in.
     *  
     *  @param cost metric associated with host (0-65535).
     */
    bool send_add_or_configure_host(
	const char*	target_name, 
	const IPv4&	network, 
	const IPv4&	netmask, 
	const uint32_t&	area_id, 
	const uint32_t&	cost, 
	const CB30&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB31;
    /**
     *  Send Xrl intended to:
     *  
     *  Delete host identified by network and netmask
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_delete_host(
	const char*	target_name, 
	const IPv4&	network, 
	const IPv4&	netmask, 
	const uint32_t&	area_id, 
	const CB31&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB32;
    /**
     *  Send Xrl intended to:
     *  
     *  Query host identified by network and netmask
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_query_host(
	const char*	target_name, 
	const IPv4&	network, 
	const IPv4&	netmask, 
	const uint32_t&	area_id, 
	const CB32&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const XrlAtomList*, const XrlAtomList*>::RefPtr CB33;
    /**
     *  Send Xrl intended to:
     *  
     *  Return list of host identifiers for area identified by area_id. Two
     *  lists are returned, the nth elements in each list comprise the tuple
     *  (network,netmask) that uniquely identifies the host within the area.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_list_hosts(
	const char*	target_name, 
	const uint32_t&	area_id, 
	const CB33&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB34;

    bool send_add_vlink(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const CB34&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB35;

    bool send_delete_vlink(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const CB35&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB36;

    bool send_vlink_set_transmit_delay(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const uint32_t&	delay_secs, 
	const CB36&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB37;

    bool send_vlink_get_transmit_delay(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const CB37&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB38;

    bool send_vlink_set_retransmit_interval(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const uint32_t&	interval_secs, 
	const CB38&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB39;

    bool send_vlink_get_retransmit_interval(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const CB39&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB40;

    bool send_vlink_set_hello_interval(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const uint32_t&	interval_secs, 
	const CB40&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB41;

    bool send_vlink_get_hello_interval(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const CB41&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB42;

    bool send_vlink_set_router_dead_interval(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const uint32_t&	interval_secs, 
	const CB42&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB43;

    bool send_vlink_get_router_dead_interval(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const CB43&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB44;
    /**
     *  Send Xrl intended to:
     *  
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param type is one of "none", "cleartext", "md5"
     */
    bool send_vlink_set_authentication(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const string&	type, 
	const string&	key, 
	const CB44&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const string*, const string*>::RefPtr CB45;

    bool send_vlink_get_authentication(
	const char*	target_name, 
	const uint32_t&	transit_area, 
	const uint32_t&	neighbor_id, 
	const CB45&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr CB46;
    /**
     *  Send Xrl intended to:
     *  
     *  Return list of neighbour id's (unsigned 32 bit values)
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_list_vlinks(
	const char*	target_name, 
	const uint32_t&	transit_id, 
	const CB46&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB47;

    bool send_add_or_configure_external_route(
	const char*	target_name, 
	const IPv4Net&	network, 
	const IPv4&	gateway, 
	const uint32_t&	type, 
	const uint32_t&	cost, 
	const bool&	multicast, 
	const uint32_t&	external_route_tag, 
	const CB47&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB48;

    bool send_delete_external_route(
	const char*	target_name, 
	const IPv4Net&	network, 
	const IPv4&	gateway, 
	const CB48&	cb
    );

    typedef XorpCallback5<void, const XrlError&, const uint32_t*, const uint32_t*, const bool*, const uint32_t*>::RefPtr CB49;

    bool send_query_external_route(
	const char*	target_name, 
	const IPv4Net&	network, 
	const IPv4&	gateway, 
	const CB49&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr CB50;

    bool send_list_external_routes(
	const char*	target_name, 
	const IPv4Net&	network, 
	const CB50&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB51;

    bool send_add_interface(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	if_index, 
	const uint32_t&	area_id, 
	const uint32_t&	cost, 
	const uint32_t&	mtu, 
	const string&	type, 
	const bool&	on_demand, 
	const bool&	passive, 
	const CB51&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB52;

    bool send_interface_set_if_index(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	index, 
	const CB52&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB53;

    bool send_interface_get_if_index(
	const char*	target_name, 
	const string&	identifier, 
	const CB53&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB54;

    bool send_interface_set_area_id(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	area_id, 
	const CB54&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB55;

    bool send_interface_get_area_id(
	const char*	target_name, 
	const string&	identifier, 
	const CB55&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB56;

    bool send_interface_set_cost(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	cost, 
	const CB56&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB57;

    bool send_interface_get_cost(
	const char*	target_name, 
	const string&	identifier, 
	const CB57&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB58;

    bool send_interface_set_mtu(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	mtu, 
	const CB58&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB59;

    bool send_interface_get_mtu(
	const char*	target_name, 
	const string&	identifier, 
	const CB59&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB60;

    bool send_interface_set_type(
	const char*	target_name, 
	const string&	identifier, 
	const string&	type, 
	const CB60&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr CB61;

    bool send_interface_get_type(
	const char*	target_name, 
	const string&	identifier, 
	const CB61&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB62;

    bool send_interface_set_dr_priority(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	dr_priority, 
	const CB62&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB63;

    bool send_interface_get_dr_priority(
	const char*	target_name, 
	const string&	identifier, 
	const CB63&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB64;

    bool send_interface_set_transit_delay(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	delay_secs, 
	const CB64&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB65;

    bool send_interface_get_transit_delay(
	const char*	target_name, 
	const string&	identifier, 
	const CB65&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB66;

    bool send_interface_set_retransmit_interval(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	interval_secs, 
	const CB66&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB67;

    bool send_interface_get_retransmit_interval(
	const char*	target_name, 
	const string&	identifier, 
	const CB67&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB68;

    bool send_interface_set_router_dead_interval(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	interval_secs, 
	const CB68&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB69;

    bool send_interface_get_router_dead_interval(
	const char*	target_name, 
	const string&	identifier, 
	const CB69&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB70;

    bool send_interface_set_poll_interval(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	interval_secs, 
	const CB70&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB71;

    bool send_interface_get_poll_interval(
	const char*	target_name, 
	const string&	identifier, 
	const CB71&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB72;

    bool send_interface_set_authentication(
	const char*	target_name, 
	const string&	identifier, 
	const string&	type, 
	const string&	key, 
	const CB72&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const string*, const string*>::RefPtr CB73;

    bool send_interface_get_authentication(
	const char*	target_name, 
	const string&	identifier, 
	const CB73&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB74;
    /**
     *  Send Xrl intended to:
     *  
     *  Set state of multicast forwarding on interface.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param type multicast type can be one of three values: "blocked"
     *  meaning not enabled, "multicast" meaning data-link multicast, or
     *  "unicast" meaning multicast packets should be unicast on data-link.
     */
    bool send_interface_set_multicast_forwarding(
	const char*	target_name, 
	const string&	identifier, 
	const string&	type, 
	const CB74&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr CB75;

    bool send_interface_get_multicast_forwarding(
	const char*	target_name, 
	const string&	identifier, 
	const CB75&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB76;

    bool send_interface_set_on_demand(
	const char*	target_name, 
	const string&	identifier, 
	const bool&	on_demand, 
	const CB76&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr CB77;

    bool send_interface_get_on_demand(
	const char*	target_name, 
	const string&	identifier, 
	const CB77&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB78;

    bool send_interface_set_passive(
	const char*	target_name, 
	const string&	identifier, 
	const bool&	passive, 
	const CB78&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr CB79;

    bool send_interface_get_passive(
	const char*	target_name, 
	const string&	identifier, 
	const CB79&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB80;

    bool send_interface_set_igmp(
	const char*	target_name, 
	const string&	identifier, 
	const bool&	enabled, 
	const CB80&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr CB81;

    bool send_interface_get_igmp(
	const char*	target_name, 
	const string&	identifier, 
	const CB81&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB82;

    bool send_delete_interface(
	const char*	target_name, 
	const string&	identifier, 
	const CB82&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr CB83;

    bool send_list_interfaces(
	const char*	target_name, 
	const CB83&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB84;
    /**
     *  Send Xrl intended to:
     *  
     *  Add md5 key to interface. The key may be used for both receiving and
     *  transmitting packets. Separate time periods are used to describe when
     *  the key is valid for receiving and transmitting. These periods are
     *  bound by times start_receive, stop_receive and start_transmit,
     *  stop_transmit. The expected date format is "%Y-%m-%d %H:%M:%S". This
     *  code uses strptime and strftime internally.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param identifier interface key is to be used for.
     *  
     *  @param key_id a value between 1-255 that identifies the key.
     */
    bool send_interface_add_md5_key(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	key_id, 
	const string&	md5key, 
	const string&	start_receive, 
	const string&	stop_receive, 
	const string&	start_transmit, 
	const string&	stop_transmit, 
	const CB84&	cb
    );

    typedef XorpCallback6<void, const XrlError&, const string*, const string*, const string*, const string*, const string*>::RefPtr CB85;

    bool send_interface_get_md5_key(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	key_id, 
	const CB85&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB86;

    bool send_interface_delete_md5_key(
	const char*	target_name, 
	const string&	identifier, 
	const uint32_t&	key_id, 
	const CB86&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr CB87;

    bool send_interface_list_md5_keys(
	const char*	target_name, 
	const string&	identifier, 
	const CB87&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB88;

    bool send_add_neighbor(
	const char*	target_name, 
	const IPv4&	nbr_addr, 
	const bool&	dr_eligible, 
	const CB88&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr CB89;

    bool send_get_neighbor(
	const char*	target_name, 
	const IPv4&	nbr_addr, 
	const CB89&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB90;

    bool send_delete_neighbor(
	const char*	target_name, 
	const IPv4&	nbr_addr, 
	const CB90&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr CB91;

    bool send_list_neighbors(
	const char*	target_name, 
	const CB91&	cb
    );

protected:
    XrlRouter* _router;

private:
    void unmarshall0(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB0		cb
    );

    void unmarshall1(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB1		cb
    );

    void unmarshall2(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB2		cb
    );

    void unmarshall3(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB3		cb
    );

    void unmarshall4(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB4		cb
    );

    void unmarshall5(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB5		cb
    );

    void unmarshall6(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB6		cb
    );

    void unmarshall7(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB7		cb
    );

    void unmarshall8(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB8		cb
    );

    void unmarshall9(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB9		cb
    );

    void unmarshall10(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB10		cb
    );

    void unmarshall11(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB11		cb
    );

    void unmarshall12(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB12		cb
    );

    void unmarshall13(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB13		cb
    );

    void unmarshall14(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB14		cb
    );

    void unmarshall15(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB15		cb
    );

    void unmarshall16(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB16		cb
    );

    void unmarshall17(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB17		cb
    );

    void unmarshall18(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB18		cb
    );

    void unmarshall19(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB19		cb
    );

    void unmarshall20(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB20		cb
    );

    void unmarshall21(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB21		cb
    );

    void unmarshall22(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB22		cb
    );

    void unmarshall23(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB23		cb
    );

    void unmarshall24(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB24		cb
    );

    void unmarshall25(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB25		cb
    );

    void unmarshall26(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB26		cb
    );

    void unmarshall27(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB27		cb
    );

    void unmarshall28(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB28		cb
    );

    void unmarshall29(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB29		cb
    );

    void unmarshall30(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB30		cb
    );

    void unmarshall31(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB31		cb
    );

    void unmarshall32(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB32		cb
    );

    void unmarshall33(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB33		cb
    );

    void unmarshall34(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB34		cb
    );

    void unmarshall35(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB35		cb
    );

    void unmarshall36(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB36		cb
    );

    void unmarshall37(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB37		cb
    );

    void unmarshall38(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB38		cb
    );

    void unmarshall39(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB39		cb
    );

    void unmarshall40(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB40		cb
    );

    void unmarshall41(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB41		cb
    );

    void unmarshall42(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB42		cb
    );

    void unmarshall43(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB43		cb
    );

    void unmarshall44(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB44		cb
    );

    void unmarshall45(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB45		cb
    );

    void unmarshall46(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB46		cb
    );

    void unmarshall47(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB47		cb
    );

    void unmarshall48(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB48		cb
    );

    void unmarshall49(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB49		cb
    );

    void unmarshall50(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB50		cb
    );

    void unmarshall51(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB51		cb
    );

    void unmarshall52(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB52		cb
    );

    void unmarshall53(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB53		cb
    );

    void unmarshall54(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB54		cb
    );

    void unmarshall55(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB55		cb
    );

    void unmarshall56(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB56		cb
    );

    void unmarshall57(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB57		cb
    );

    void unmarshall58(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB58		cb
    );

    void unmarshall59(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB59		cb
    );

    void unmarshall60(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB60		cb
    );

    void unmarshall61(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB61		cb
    );

    void unmarshall62(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB62		cb
    );

    void unmarshall63(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB63		cb
    );

    void unmarshall64(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB64		cb
    );

    void unmarshall65(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB65		cb
    );

    void unmarshall66(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB66		cb
    );

    void unmarshall67(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB67		cb
    );

    void unmarshall68(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB68		cb
    );

    void unmarshall69(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB69		cb
    );

    void unmarshall70(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB70		cb
    );

    void unmarshall71(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB71		cb
    );

    void unmarshall72(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB72		cb
    );

    void unmarshall73(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB73		cb
    );

    void unmarshall74(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB74		cb
    );

    void unmarshall75(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB75		cb
    );

    void unmarshall76(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB76		cb
    );

    void unmarshall77(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB77		cb
    );

    void unmarshall78(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB78		cb
    );

    void unmarshall79(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB79		cb
    );

    void unmarshall80(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB80		cb
    );

    void unmarshall81(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB81		cb
    );

    void unmarshall82(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB82		cb
    );

    void unmarshall83(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB83		cb
    );

    void unmarshall84(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB84		cb
    );

    void unmarshall85(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB85		cb
    );

    void unmarshall86(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB86		cb
    );

    void unmarshall87(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB87		cb
    );

    void unmarshall88(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB88		cb
    );

    void unmarshall89(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB89		cb
    );

    void unmarshall90(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB90		cb
    );

    void unmarshall91(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB91		cb
    );

};

#endif /* __XRL_INTERFACES_OSPF_XIF_HH__ */
