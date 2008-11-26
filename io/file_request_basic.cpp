/***************************************************************************
 *  io/file_request_basic.cpp
 *
 *  Part of the STXXL. See http://stxxl.sourceforge.net
 *
 *  Copyright (C) 2008 Andreas Beckmann <beckmann@cs.uni-frankfurt.de>
 *
 *  Distributed under the Boost Software License, Version 1.0.
 *  (See accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 **************************************************************************/

#include <stxxl/bits/io/file_request_basic.h>
#include <stxxl/bits/io/request_impl_basic.h>
#include <stxxl/bits/io/disk_queues.h>


__STXXL_BEGIN_NAMESPACE


request_ptr file_request_basic::aread(
    void * buffer,
    stxxl::int64 pos,
    size_t bytes,
    const completion_handler & on_cmpl)
{
    request_ptr req = new request_impl_basic(on_cmpl, this,
                                          buffer, pos, bytes,
                                          request::READ);

    disk_queues::get_instance()->add_request(req, get_id());

    return req;
}

request_ptr file_request_basic::awrite(
    void * buffer,
    stxxl::int64 pos,
    size_t bytes,
    const completion_handler & on_cmpl)
{
    request_ptr req = new request_impl_basic(on_cmpl, this, buffer, pos, bytes,
                                          request::WRITE);

    disk_queues::get_instance()->add_request(req, get_id());

    return req;
}

__STXXL_END_NAMESPACE
// vim: et:ts=4:sw=4