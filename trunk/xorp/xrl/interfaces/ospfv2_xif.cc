/*
 * Copyright (c) 2001-2005 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/ospfv2_xif.cc,v 1.13 2006/01/03 02:24:12 atanu Exp $"

#include "ospfv2_xif.hh"

bool
XrlOspfv2V0p1Client::send_set_router_id(
	const char*	the_tgt,
	const IPv4&	id,
	const SetRouterIdCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/set_router_id");
    x.args().add("id", id);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_set_router_id, cb));
}


/* Unmarshall set_router_id */
void
XrlOspfv2V0p1Client::unmarshall_set_router_id(
	const XrlError&	e,
	XrlArgs*	a,
	SetRouterIdCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_set_ip_router_alert(
	const char*	the_tgt,
	const bool&	ip_router_alert,
	const SetIpRouterAlertCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/set_ip_router_alert");
    x.args().add("ip_router_alert", ip_router_alert);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_set_ip_router_alert, cb));
}


/* Unmarshall set_ip_router_alert */
void
XrlOspfv2V0p1Client::unmarshall_set_ip_router_alert(
	const XrlError&	e,
	XrlArgs*	a,
	SetIpRouterAlertCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_create_area_router(
	const char*	the_tgt,
	const IPv4&	area,
	const string&	type,
	const CreateAreaRouterCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/create_area_router");
    x.args().add("area", area);
    x.args().add("type", type);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_create_area_router, cb));
}


/* Unmarshall create_area_router */
void
XrlOspfv2V0p1Client::unmarshall_create_area_router(
	const XrlError&	e,
	XrlArgs*	a,
	CreateAreaRouterCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_destroy_area_router(
	const char*	the_tgt,
	const IPv4&	area,
	const DestroyAreaRouterCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/destroy_area_router");
    x.args().add("area", area);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_destroy_area_router, cb));
}


/* Unmarshall destroy_area_router */
void
XrlOspfv2V0p1Client::unmarshall_destroy_area_router(
	const XrlError&	e,
	XrlArgs*	a,
	DestroyAreaRouterCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_create_peer(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	prefix_len,
	const uint32_t&	mtu,
	const string&	type,
	const IPv4&	area,
	const CreatePeerCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/create_peer");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("prefix_len", prefix_len);
    x.args().add("mtu", mtu);
    x.args().add("type", type);
    x.args().add("area", area);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_create_peer, cb));
}


/* Unmarshall create_peer */
void
XrlOspfv2V0p1Client::unmarshall_create_peer(
	const XrlError&	e,
	XrlArgs*	a,
	CreatePeerCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_delete_peer(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const DeletePeerCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/delete_peer");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_delete_peer, cb));
}


/* Unmarshall delete_peer */
void
XrlOspfv2V0p1Client::unmarshall_delete_peer(
	const XrlError&	e,
	XrlArgs*	a,
	DeletePeerCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_set_peer_state(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const bool&	enable,
	const SetPeerStateCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/set_peer_state");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("enable", enable);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_set_peer_state, cb));
}


/* Unmarshall set_peer_state */
void
XrlOspfv2V0p1Client::unmarshall_set_peer_state(
	const XrlError&	e,
	XrlArgs*	a,
	SetPeerStateCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_add_neighbour(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	area,
	const IPv4&	neighbour_address,
	const IPv4&	neighbour_id,
	const AddNeighbourCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/add_neighbour");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("area", area);
    x.args().add("neighbour_address", neighbour_address);
    x.args().add("neighbour_id", neighbour_id);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_add_neighbour, cb));
}


/* Unmarshall add_neighbour */
void
XrlOspfv2V0p1Client::unmarshall_add_neighbour(
	const XrlError&	e,
	XrlArgs*	a,
	AddNeighbourCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_remove_neighbour(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	area,
	const IPv4&	neighbour_address,
	const IPv4&	neighbour_id,
	const RemoveNeighbourCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/remove_neighbour");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("area", area);
    x.args().add("neighbour_address", neighbour_address);
    x.args().add("neighbour_id", neighbour_id);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_remove_neighbour, cb));
}


/* Unmarshall remove_neighbour */
void
XrlOspfv2V0p1Client::unmarshall_remove_neighbour(
	const XrlError&	e,
	XrlArgs*	a,
	RemoveNeighbourCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_create_virtual_link(
	const char*	the_tgt,
	const IPv4&	neighbour_id,
	const IPv4&	area,
	const CreateVirtualLinkCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/create_virtual_link");
    x.args().add("neighbour_id", neighbour_id);
    x.args().add("area", area);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_create_virtual_link, cb));
}


/* Unmarshall create_virtual_link */
void
XrlOspfv2V0p1Client::unmarshall_create_virtual_link(
	const XrlError&	e,
	XrlArgs*	a,
	CreateVirtualLinkCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_delete_virtual_link(
	const char*	the_tgt,
	const IPv4&	neighbour_id,
	const DeleteVirtualLinkCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/delete_virtual_link");
    x.args().add("neighbour_id", neighbour_id);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_delete_virtual_link, cb));
}


/* Unmarshall delete_virtual_link */
void
XrlOspfv2V0p1Client::unmarshall_delete_virtual_link(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteVirtualLinkCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_transit_area_virtual_link(
	const char*	the_tgt,
	const IPv4&	neighbour_id,
	const IPv4&	transit_area,
	const TransitAreaVirtualLinkCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/transit_area_virtual_link");
    x.args().add("neighbour_id", neighbour_id);
    x.args().add("transit_area", transit_area);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_transit_area_virtual_link, cb));
}


/* Unmarshall transit_area_virtual_link */
void
XrlOspfv2V0p1Client::unmarshall_transit_area_virtual_link(
	const XrlError&	e,
	XrlArgs*	a,
	TransitAreaVirtualLinkCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_set_interface_cost(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	area,
	const uint32_t&	cost,
	const SetInterfaceCostCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/set_interface_cost");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("area", area);
    x.args().add("cost", cost);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_set_interface_cost, cb));
}


/* Unmarshall set_interface_cost */
void
XrlOspfv2V0p1Client::unmarshall_set_interface_cost(
	const XrlError&	e,
	XrlArgs*	a,
	SetInterfaceCostCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_set_retransmit_interval(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	area,
	const uint32_t&	interval,
	const SetRetransmitIntervalCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/set_retransmit_interval");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("area", area);
    x.args().add("interval", interval);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_set_retransmit_interval, cb));
}


/* Unmarshall set_retransmit_interval */
void
XrlOspfv2V0p1Client::unmarshall_set_retransmit_interval(
	const XrlError&	e,
	XrlArgs*	a,
	SetRetransmitIntervalCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_set_inftransdelay(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	area,
	const uint32_t&	delay,
	const SetInftransdelayCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/set_inftransdelay");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("area", area);
    x.args().add("delay", delay);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_set_inftransdelay, cb));
}


/* Unmarshall set_inftransdelay */
void
XrlOspfv2V0p1Client::unmarshall_set_inftransdelay(
	const XrlError&	e,
	XrlArgs*	a,
	SetInftransdelayCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_set_router_priority(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	area,
	const uint32_t&	priority,
	const SetRouterPriorityCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/set_router_priority");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("area", area);
    x.args().add("priority", priority);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_set_router_priority, cb));
}


/* Unmarshall set_router_priority */
void
XrlOspfv2V0p1Client::unmarshall_set_router_priority(
	const XrlError&	e,
	XrlArgs*	a,
	SetRouterPriorityCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_set_hello_interval(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	area,
	const uint32_t&	interval,
	const SetHelloIntervalCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/set_hello_interval");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("area", area);
    x.args().add("interval", interval);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_set_hello_interval, cb));
}


/* Unmarshall set_hello_interval */
void
XrlOspfv2V0p1Client::unmarshall_set_hello_interval(
	const XrlError&	e,
	XrlArgs*	a,
	SetHelloIntervalCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_set_router_dead_interval(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	area,
	const uint32_t&	interval,
	const SetRouterDeadIntervalCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/set_router_dead_interval");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("area", area);
    x.args().add("interval", interval);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_set_router_dead_interval, cb));
}


/* Unmarshall set_router_dead_interval */
void
XrlOspfv2V0p1Client::unmarshall_set_router_dead_interval(
	const XrlError&	e,
	XrlArgs*	a,
	SetRouterDeadIntervalCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_set_authentication(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	area,
	const string&	type,
	const string&	password,
	const SetAuthenticationCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/set_authentication");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("area", area);
    x.args().add("type", type);
    x.args().add("password", password);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_set_authentication, cb));
}


/* Unmarshall set_authentication */
void
XrlOspfv2V0p1Client::unmarshall_set_authentication(
	const XrlError&	e,
	XrlArgs*	a,
	SetAuthenticationCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_area_range_add(
	const char*	the_tgt,
	const IPv4&	area,
	const IPv4Net&	net,
	const bool&	advertise,
	const AreaRangeAddCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/area_range_add");
    x.args().add("area", area);
    x.args().add("net", net);
    x.args().add("advertise", advertise);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_area_range_add, cb));
}


/* Unmarshall area_range_add */
void
XrlOspfv2V0p1Client::unmarshall_area_range_add(
	const XrlError&	e,
	XrlArgs*	a,
	AreaRangeAddCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_area_range_delete(
	const char*	the_tgt,
	const IPv4&	area,
	const IPv4Net&	net,
	const AreaRangeDeleteCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/area_range_delete");
    x.args().add("area", area);
    x.args().add("net", net);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_area_range_delete, cb));
}


/* Unmarshall area_range_delete */
void
XrlOspfv2V0p1Client::unmarshall_area_range_delete(
	const XrlError&	e,
	XrlArgs*	a,
	AreaRangeDeleteCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_area_range_change_state(
	const char*	the_tgt,
	const IPv4&	area,
	const IPv4Net&	net,
	const bool&	advertise,
	const AreaRangeChangeStateCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/area_range_change_state");
    x.args().add("area", area);
    x.args().add("net", net);
    x.args().add("advertise", advertise);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_area_range_change_state, cb));
}


/* Unmarshall area_range_change_state */
void
XrlOspfv2V0p1Client::unmarshall_area_range_change_state(
	const XrlError&	e,
	XrlArgs*	a,
	AreaRangeChangeStateCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_trace(
	const char*	the_tgt,
	const string&	tvar,
	const bool&	enable,
	const TraceCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/trace");
    x.args().add("tvar", tvar);
    x.args().add("enable", enable);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_trace, cb));
}


/* Unmarshall trace */
void
XrlOspfv2V0p1Client::unmarshall_trace(
	const XrlError&	e,
	XrlArgs*	a,
	TraceCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlOspfv2V0p1Client::send_get_lsa(
	const char*	the_tgt,
	const IPv4&	area,
	const uint32_t&	index,
	const GetLsaCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/get_lsa");
    x.args().add("area", area);
    x.args().add("index", index);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_get_lsa, cb));
}


/* Unmarshall get_lsa */
void
XrlOspfv2V0p1Client::unmarshall_get_lsa(
	const XrlError&	e,
	XrlArgs*	a,
	GetLsaCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 4) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(4));
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0);
	return;
    }
    bool valid;
    bool toohigh;
    bool self;
    vector<uint8_t> lsa;
    try {
	a->get("valid", valid);
	a->get("toohigh", toohigh);
	a->get("self", self);
	a->get("lsa", lsa);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &valid, &toohigh, &self, &lsa);
}

bool
XrlOspfv2V0p1Client::send_get_area_list(
	const char*	the_tgt,
	const GetAreaListCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/get_area_list");
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_get_area_list, cb));
}


/* Unmarshall get_area_list */
void
XrlOspfv2V0p1Client::unmarshall_get_area_list(
	const XrlError&	e,
	XrlArgs*	a,
	GetAreaListCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    XrlAtomList areas;
    try {
	a->get("areas", areas);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &areas);
}

bool
XrlOspfv2V0p1Client::send_get_neighbour_list(
	const char*	the_tgt,
	const GetNeighbourListCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/get_neighbour_list");
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_get_neighbour_list, cb));
}


/* Unmarshall get_neighbour_list */
void
XrlOspfv2V0p1Client::unmarshall_get_neighbour_list(
	const XrlError&	e,
	XrlArgs*	a,
	GetNeighbourListCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    XrlAtomList areas;
    try {
	a->get("areas", areas);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &areas);
}

bool
XrlOspfv2V0p1Client::send_get_neighbour_info(
	const char*	the_tgt,
	const uint32_t&	nid,
	const GetNeighbourInfoCB&	cb
)
{
    Xrl x(the_tgt, "ospfv2/0.1/get_neighbour_info");
    x.args().add("nid", nid);
    return _sender->send(x, callback(this, &XrlOspfv2V0p1Client::unmarshall_get_neighbour_info, cb));
}


/* Unmarshall get_neighbour_info */
void
XrlOspfv2V0p1Client::unmarshall_get_neighbour_info(
	const XrlError&	e,
	XrlArgs*	a,
	GetNeighbourInfoCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 12) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(12));
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    string address;
    string interface;
    string state;
    IPv4 rid;
    uint32_t priority;
    uint32_t deadtime;
    IPv4 area;
    uint32_t opt;
    IPv4 dr;
    IPv4 bdr;
    uint32_t up;
    uint32_t adjacent;
    try {
	a->get("address", address);
	a->get("interface", interface);
	a->get("state", state);
	a->get("rid", rid);
	a->get("priority", priority);
	a->get("deadtime", deadtime);
	a->get("area", area);
	a->get("opt", opt);
	a->get("dr", dr);
	a->get("bdr", bdr);
	a->get("up", up);
	a->get("adjacent", adjacent);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &address, &interface, &state, &rid, &priority, &deadtime, &area, &opt, &dr, &bdr, &up, &adjacent);
}
