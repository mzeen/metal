// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_TRAITS_HPP
#define BOOST_MPL2_LAMBDA_TRAITS_HPP

#include <boost/mpl2/lambda/logical/and.hpp>
#include <boost/mpl2/lambda/logical/or.hpp>
#include <boost/mpl2/lambda/nested_type_trait.hpp>
#include <boost/mpl2/lambda/nested_template_trait.hpp>
#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/function.hpp>
#include <boost/mpl2/lambda/nullary.hpp>
#include <boost/mpl2/lambda/bind.hpp>
#include <boost/mpl2/lambda/call.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_type, type);
            BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(has_call, call);

            template<typename x, typename... args>
            struct is_call_valid
            {
            private:
                template<template<typename...> class y>
                static boost::mpl2::true_ check(y<args...>*);
                template<template<typename...> class>
                static boost::mpl2::false_ check(...);

            public:
                using type = decltype(check<x::template call>(0));
                using value_type = typename type::value_type;
                static constexpr value_type value = type::value;
                constexpr operator value_type() const noexcept {return value;}
                constexpr value_type operator()() const noexcept {return value;}
            };

            template<typename x, typename... args>
            struct is_call_defined :
                    std::is_constructible<typename x::template call<args...> >
            {};
        }

        template<typename x, typename... args>
        using is_callable = and_<
            detail::has_call<x>,
            detail::is_call_valid<x, args...>,
            detail::is_call_defined<x, args...>,
            detail::has_type<call<x, args...> >
        >;

        template<typename x>
        struct is_function :
                and_<
                    detail::has_call<x>,
                    detail::has_type<x>,
                    or_<
                        call<
                            bind<
                                function<std::is_same>,
                                bind<nullary<identity<x> > >,
                                bind<nullary<x> >
                            >
                        >,
                        call<
                            bind<
                                function<is_function>,
                                bind<nullary<x> >
                            >
                        >
                    >
                >
        {};
    }
}

#endif