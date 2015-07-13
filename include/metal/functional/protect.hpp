// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_PROTECT_HPP
#define METAL_FUNCTIONAL_PROTECT_HPP

#include <metal/functional/detail/nullable.hpp>

namespace metal
{
    namespace detail
    {
        template<typename nullable, int = 0>
        struct protect_impl :
                detail::nullable<nullable>
        {
            using type = protect_impl;
        };
    }

    template<typename nullable>
    using protect = detail::protect_impl<nullable>;
}

#endif
