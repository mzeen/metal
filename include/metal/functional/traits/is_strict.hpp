// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_STRICT_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_STRICT_HPP

#include <metal/functional/traits/is_nil.hpp>
#include <metal/algebra/logical/not.hpp>
#include <metal/algebra/logical/and.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename value>
        struct is_strict_impl :
                std::is_base_of<typename value::type, value>
        {};
    }

    template<typename value>
    struct is_strict :
            and_<
                not_<is_nil<value>>,
                detail::is_strict_impl<value>
            >
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for is_strict.
    template<typename value>
    using is_strict_t = typename is_strict<value>::type;
}

#endif