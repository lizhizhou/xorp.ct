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

#ident "$XORP: xorp/policy/then.cc,v 1.1 2003/02/13 00:51:04 mjh Exp $"

#include "policy_module.h"
#include "then.hh"

template <class A>
PolicyThen<A>::PolicyThen<A>(bool reject)
{
    UNUSED(reject);
}

template <class A>
PolicyThen<A>::~PolicyThen()
{
}

template <class A>
void 
PolicyThen<A>::add_policy_action(const PolicyAction<A>& action)
{
    _actions.push_back(action);
}

template <class A>
bool 
PolicyThen<A>::apply_actions(const PolicyRoute<A>& in_route, 
			     PolicyRoute<A>*& out_route) const
{
    out_route = &in_route;
    return true;
}
