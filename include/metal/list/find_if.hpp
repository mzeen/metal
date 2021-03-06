// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FIND_IF_HPP
#define METAL_LIST_FIND_IF_HPP

#include "../config.hpp"
#include "../list/transform.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename seq>
        struct _find_if;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Returns the index of the first element of a \list that satisfy a
    /// predicate.
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::find_if<l, lbd>;
    /// \endcode
    ///
    /// \pre: For any element `l[i]` contained in `l`,
    /// `metal::invoke<lbd, l[i]>` returns a \number
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<i>;
    ///     \endcode
    ///     where `i` is such that `l[i]` is the first element in `l` for which
    ///     `metal::invoke<lbd, l[i]>{} != false`, otherwise
    ///     \code
    ///         using result = metal::size<l>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp find_if
    ///
    /// ### See Also
    /// \see list, find, all, any, none, count_if
    template<typename seq, typename lbd>
    using find_if = typename detail::_find_if<transform<lbd, seq>>::type;
}

#include "../list/front.hpp"
#include "../list/indices.hpp"
#include "../list/join.hpp"
#include "../list/list.hpp"
#include "../number/if.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename seq, typename = indices<seq>>
        struct _find_index {};

        template<int_... vs, typename... is>
        struct _find_index<list<number<vs>...>, list<is...>> {
            using type = front<join<if_<number<vs>, list<is>, list<>>...>>;
        };

        template<typename seq>
        struct _find_if {};

        template<>
        struct _find_if<list<>> : number<0> {};

        template<int_... vs>
        struct _find_if<list<number<vs>...>>
            : _find_index<list<number<vs>..., true_>> {};
    }
    /// \endcond
}

#endif
