/*
    Copyright (c) 2013-2014 Contributors as noted in the AUTHORS file

    This file is part of azmq

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
#ifndef AZMQ_CONTEXT_HPP_
#define AZMQ_CONTEXT_HPP_

#include "detail/socket_service.hpp"
#include "option.hpp"
#include "error.hpp"

#include <asio/io_service.hpp>
#include <zmq.h>

namespace azmq {

    using io_threads = detail::context_ops::io_threads;
    using max_sockets = detail::context_ops::max_sockets;
    using ipv6 = detail::context_ops::ipv6;

    /** \brief set options on the zeromq context.
     *  \tparam Option option type
     *  \param option Option option to set
     *  \remark Must be called before any sockets are created
     */
    template<typename Option>
    asio::error_code set_option(asio::io_service & io_service,
                                         const Option & option,
                                         asio::error_code & ec) {
        return asio::use_service<detail::socket_service>(io_service).set_option(option, ec);
    }

    /** \brief set options on the zeromq context.
     *  \tparam Option option type
     *  \param option Option option to set
     *  \remark Must be called before any sockets are created
     */
    template<typename Option>
    void set_option(asio::io_service & io_service, const Option & option) {
        asio::error_code ec;
        if (set_option(io_service, option, ec))
            throw asio::system_error(ec);
    }

    /** \brief get option from zeromq context
     *  \tparam Option option type
     *  \param option Option te get
     *  \param ec asio::error_code
     */
    template<typename Option>
    asio::error_code get_option(asio::io_service & io_service,
                                         Option & option,
                                         asio::error_code & ec) {
        return asio::use_service<detail::socket_service>(io_service).get_option(option, ec);
    }

    /** \brief get option from zeromq context
     *  \tparam Option option type
     *  \param option Option te get
     *  \param ec asio::error_code
     */
    template<typename Option>
    void get_option(asio::io_service & io_service, Option & option) {
        asio::error_code ec;
        if (get_option(io_service, option))
            throw asio::system_error(ec);
    }

} // namespace azmq
#endif // AZMQ_CONTEXT_HPP_
