/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP$"

#include "cli_manager_xif.hh"

bool
XrlCliManagerV0p1Client::send_enable_cli(
	const char*	the_tgt, 
	const EnableCliCB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/enable_cli");
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_enable_cli, cb));
}


/* Unmarshall enable_cli */
void
XrlCliManagerV0p1Client::unmarshall_enable_cli(
	const XrlError&	e, 
	XrlArgs*	a, 
	EnableCliCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_disable_cli(
	const char*	the_tgt, 
	const DisableCliCB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/disable_cli");
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_disable_cli, cb));
}


/* Unmarshall disable_cli */
void
XrlCliManagerV0p1Client::unmarshall_disable_cli(
	const XrlError&	e, 
	XrlArgs*	a, 
	DisableCliCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_start_cli(
	const char*	the_tgt, 
	const StartCliCB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/start_cli");
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_start_cli, cb));
}


/* Unmarshall start_cli */
void
XrlCliManagerV0p1Client::unmarshall_start_cli(
	const XrlError&	e, 
	XrlArgs*	a, 
	StartCliCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_stop_cli(
	const char*	the_tgt, 
	const StopCliCB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/stop_cli");
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_stop_cli, cb));
}


/* Unmarshall stop_cli */
void
XrlCliManagerV0p1Client::unmarshall_stop_cli(
	const XrlError&	e, 
	XrlArgs*	a, 
	StopCliCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_add_enable_cli_access_from_subnet4(
	const char*	the_tgt, 
	const IPv4Net&	subnet_addr, 
	const AddEnableCliAccessFromSubnet4CB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/add_enable_cli_access_from_subnet4");
    x.args().add("subnet_addr", subnet_addr);
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_add_enable_cli_access_from_subnet4, cb));
}


/* Unmarshall add_enable_cli_access_from_subnet4 */
void
XrlCliManagerV0p1Client::unmarshall_add_enable_cli_access_from_subnet4(
	const XrlError&	e, 
	XrlArgs*	a, 
	AddEnableCliAccessFromSubnet4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_add_enable_cli_access_from_subnet6(
	const char*	the_tgt, 
	const IPv6Net&	subnet_addr, 
	const AddEnableCliAccessFromSubnet6CB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/add_enable_cli_access_from_subnet6");
    x.args().add("subnet_addr", subnet_addr);
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_add_enable_cli_access_from_subnet6, cb));
}


/* Unmarshall add_enable_cli_access_from_subnet6 */
void
XrlCliManagerV0p1Client::unmarshall_add_enable_cli_access_from_subnet6(
	const XrlError&	e, 
	XrlArgs*	a, 
	AddEnableCliAccessFromSubnet6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_delete_enable_cli_access_from_subnet4(
	const char*	the_tgt, 
	const IPv4Net&	subnet_addr, 
	const DeleteEnableCliAccessFromSubnet4CB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/delete_enable_cli_access_from_subnet4");
    x.args().add("subnet_addr", subnet_addr);
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_delete_enable_cli_access_from_subnet4, cb));
}


/* Unmarshall delete_enable_cli_access_from_subnet4 */
void
XrlCliManagerV0p1Client::unmarshall_delete_enable_cli_access_from_subnet4(
	const XrlError&	e, 
	XrlArgs*	a, 
	DeleteEnableCliAccessFromSubnet4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_delete_enable_cli_access_from_subnet6(
	const char*	the_tgt, 
	const IPv6Net&	subnet_addr, 
	const DeleteEnableCliAccessFromSubnet6CB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/delete_enable_cli_access_from_subnet6");
    x.args().add("subnet_addr", subnet_addr);
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_delete_enable_cli_access_from_subnet6, cb));
}


/* Unmarshall delete_enable_cli_access_from_subnet6 */
void
XrlCliManagerV0p1Client::unmarshall_delete_enable_cli_access_from_subnet6(
	const XrlError&	e, 
	XrlArgs*	a, 
	DeleteEnableCliAccessFromSubnet6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_add_disable_cli_access_from_subnet4(
	const char*	the_tgt, 
	const IPv4Net&	subnet_addr, 
	const AddDisableCliAccessFromSubnet4CB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/add_disable_cli_access_from_subnet4");
    x.args().add("subnet_addr", subnet_addr);
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_add_disable_cli_access_from_subnet4, cb));
}


/* Unmarshall add_disable_cli_access_from_subnet4 */
void
XrlCliManagerV0p1Client::unmarshall_add_disable_cli_access_from_subnet4(
	const XrlError&	e, 
	XrlArgs*	a, 
	AddDisableCliAccessFromSubnet4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_add_disable_cli_access_from_subnet6(
	const char*	the_tgt, 
	const IPv6Net&	subnet_addr, 
	const AddDisableCliAccessFromSubnet6CB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/add_disable_cli_access_from_subnet6");
    x.args().add("subnet_addr", subnet_addr);
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_add_disable_cli_access_from_subnet6, cb));
}


/* Unmarshall add_disable_cli_access_from_subnet6 */
void
XrlCliManagerV0p1Client::unmarshall_add_disable_cli_access_from_subnet6(
	const XrlError&	e, 
	XrlArgs*	a, 
	AddDisableCliAccessFromSubnet6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_delete_disable_cli_access_from_subnet4(
	const char*	the_tgt, 
	const IPv4Net&	subnet_addr, 
	const DeleteDisableCliAccessFromSubnet4CB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/delete_disable_cli_access_from_subnet4");
    x.args().add("subnet_addr", subnet_addr);
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_delete_disable_cli_access_from_subnet4, cb));
}


/* Unmarshall delete_disable_cli_access_from_subnet4 */
void
XrlCliManagerV0p1Client::unmarshall_delete_disable_cli_access_from_subnet4(
	const XrlError&	e, 
	XrlArgs*	a, 
	DeleteDisableCliAccessFromSubnet4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_delete_disable_cli_access_from_subnet6(
	const char*	the_tgt, 
	const IPv6Net&	subnet_addr, 
	const DeleteDisableCliAccessFromSubnet6CB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/delete_disable_cli_access_from_subnet6");
    x.args().add("subnet_addr", subnet_addr);
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_delete_disable_cli_access_from_subnet6, cb));
}


/* Unmarshall delete_disable_cli_access_from_subnet6 */
void
XrlCliManagerV0p1Client::unmarshall_delete_disable_cli_access_from_subnet6(
	const XrlError&	e, 
	XrlArgs*	a, 
	DeleteDisableCliAccessFromSubnet6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_add_cli_command(
	const char*	the_tgt, 
	const string&	processor_name, 
	const string&	command_name, 
	const string&	command_help, 
	const bool&	is_command_cd, 
	const string&	command_cd_prompt, 
	const bool&	is_command_processor, 
	const AddCliCommandCB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/add_cli_command");
    x.args().add("processor_name", processor_name);
    x.args().add("command_name", command_name);
    x.args().add("command_help", command_help);
    x.args().add("is_command_cd", is_command_cd);
    x.args().add("command_cd_prompt", command_cd_prompt);
    x.args().add("is_command_processor", is_command_processor);
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_add_cli_command, cb));
}


/* Unmarshall add_cli_command */
void
XrlCliManagerV0p1Client::unmarshall_add_cli_command(
	const XrlError&	e, 
	XrlArgs*	a, 
	AddCliCommandCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlCliManagerV0p1Client::send_delete_cli_command(
	const char*	the_tgt, 
	const string&	processor_name, 
	const string&	command_name, 
	const DeleteCliCommandCB&	cb
)
{
    Xrl x(the_tgt, "cli_manager/0.1/delete_cli_command");
    x.args().add("processor_name", processor_name);
    x.args().add("command_name", command_name);
    return _sender->send(x, callback(this, &XrlCliManagerV0p1Client::unmarshall_delete_cli_command, cb));
}


/* Unmarshall delete_cli_command */
void
XrlCliManagerV0p1Client::unmarshall_delete_cli_command(
	const XrlError&	e, 
	XrlArgs*	a, 
	DeleteCliCommandCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
