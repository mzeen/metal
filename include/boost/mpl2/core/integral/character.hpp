/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef BOOST_MPL2_CORE_INTEGRAL_CHARACTER_HPP
#define BOOST_MPL2_CORE_INTEGRAL_CHARACTER_HPP

#include <boost/mpl2/core/integral.hpp>

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        template<char constant>
        struct char_ :
                integral<char, constant>
        {};

        template<unsigned char constant>
        struct uchar_ :
                integral<unsigned char, constant>
        {};

        template<signed char constant>
        struct schar_ :
                integral<signed char, constant>
        {};

        template<wchar_t constant>
        struct wchar_t_ :
                integral<wchar_t, constant>
        {};

#if defined(BOOST_HAS_CHAR16_T)
        template<char16_t constant>
        struct char16_t_ :
                integral<char16_t, constant>
        {};
#endif

#if defined(BOOST_HAS_CHAR16_T)
        template<char32_t constant>
        struct char32_t_ :
                integral<char32_t, constant>
        {};
#endif
    }
}

#endif
