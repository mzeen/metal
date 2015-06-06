// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_TRAITS_IS_QUOTABLE_HPP
#define BOOST_MPL2_METAFUNCTIONAL_TRAITS_IS_QUOTABLE_HPP

#include <boost/mpl2/metafunctional/quote.hpp>
#include <boost/mpl2/metafunctional/traits/detail/has_type.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class expr, typename... args>
        struct is_quotable :
                detail::has_type<quote<expr, args...> >
        {};
    }
}

#endif