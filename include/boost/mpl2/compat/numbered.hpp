/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL2_COMPAT_NUMBERED_HPP_
#define _BOOST_MPL2_COMPAT_NUMBERED_HPP_

#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/elem.hpp>

// FOR EACH
#define __BOOST_MPL2_FORWARD_MACRO_FOR_EACH_ARG(Z, N, DATA) \
    BOOST_PP_SEQ_ELEM(1, DATA)( \
            BOOST_PP_SEQ_ELEM(2, DATA), \
            BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(0, DATA), N) \
        )

#define __BOOST_MPL2_FOR_EACH_ARG(N, PREFIX, MACRO, DATA) \
    BOOST_PP_ENUM(N, __BOOST_MPL2_FORWARD_MACRO_FOR_EACH_ARG, (PREFIX)(MACRO)(DATA))

// CALL FOR EACH
#define __BOOST_MPL2_CALL_FOR_ARG(FUNC, ARG) \
    typename FUNC<ARG>::type

#define BOOST_MPL2_CALL_FOR_EACH_ARG(N, PREFIX, FUNC) \
    __BOOST_MPL2_FOR_EACH_ARG(N, PREFIX, __BOOST_MPL2_CALL_FOR_ARG, FUNC)

#define BOOST_MPL2_CALL_FOR_EACH_LEADING_ARG(N, PREFIX, FUNC) \
    BOOST_MPL2_CALL_FOR_EACH_ARG(N, PREFIX, FUNC) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_CALL_FOR_EACH_TRAILING_ARG(N, PREFIX, FUNC) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_CALL_FOR_EACH_ARG(N, PREFIX, FUNC)

// WRAP EACH
#define __BOOST_MPL2_WRAP_ARG(WRAP, ARG) \
    WRAP<ARG>

#define BOOST_MPL2_WRAP_EACH_ARG(N, PREFIX, WRAP) \
    __BOOST_MPL2_FOR_EACH_ARG(N, PREFIX, __BOOST_MPL2_WRAP_ARG, WRAP)

#define BOOST_MPL2_WRAP_EACH_LEADING_ARG(N, PREFIX, WRAP) \
    BOOST_MPL2_WRAP_EACH_ARG(N, PREFIX, WRAP) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_WRAP_EACH_TRAILING_ARG(N, PREFIX, WRAP) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_WRAP_EACH_ARG(N, PREFIX, WRAP)

// ARGS
#define BOOST_MPL2_ARGS(N, PREFIX) \
    BOOST_PP_ENUM_PARAMS(N, PREFIX)

#define BOOST_MPL2_LEADING_ARGS(N, PREFIX) \
    BOOST_MPL2_ARGS(N, PREFIX) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_TRAILING_ARGS(N, PREFIX) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_ARGS(N, PREFIX)

// PARAMS
#define BOOST_MPL2_PARAMS(N, PREFIX) \
    BOOST_PP_ENUM_PARAMS(N, typename PREFIX)

#define BOOST_MPL2_LEADING_PARAMS(N, PREFIX) \
    BOOST_MPL2_PARAMS(N, PREFIX) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_TRAILING_PARAMS(N, PREFIX) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_PARAMS(N, PREFIX)

// OPTIONAL PARAMS
namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            // not available
            struct na;
        }
    }
}

#define BOOST_MPL2_OPTIONAL_PARAMS(N, PREFIX) \
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(N, typename PREFIX, boost::mpl2::detail::na)

#define BOOST_MPL2_LEADING_OPTIONAL_PARAMS(N, PREFIX) \
    BOOST_MPL2_OPTIONAL_PARAMS(N, PREFIX) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_TRAILING_OPTIONAL_PARAMS(N, PREFIX) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_OPTIONAL_PARAMS(N, PREFIX)

#endif
