// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_STRICTLY_EVALUABLE_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_STRICTLY_EVALUABLE_HPP

#include <metal/functional/eval.hpp>
#include <metal/functional/traits/is_strict.hpp>

namespace metal
{
    /// \ingroup functional_traits
    /// \brief Checks whether an arbitrary \expression `expr`
    /// is strictly evaluable with \values `args`.
    ///
    /// Usage
    /// -----
    /// For any \expression `expr` and \values `args`,
    /// \code
    ///     using result = metal::is_strictly_evaluable<expr, args...>;
    /// \endcode
    /// \par Model:
    ///     \number
    /// \par Semantics:
    ///     if `expr<args...>` is well defined and \strict, then equivalent to
    ///     \code
    ///         struct result :
    ///             std::true_type
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         struct result :
    ///             std::false_type
    ///         {};
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet functional/traits/is_strictly_evaluable.cpp main
    ///
    /// See Also
    /// --------
    /// \see is_strictly_evaluable_t, is_evaluable, eval
    template<template<typename...> class expr, typename... args>
    struct is_strictly_evaluable :
            is_strict<eval<expr, args...>>
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for \ref is_strictly_evaluable.
    template<template<typename...> class expr, typename... args>
    using is_strictly_evaluable_t =
        typename is_strictly_evaluable<expr, args...>::type;
}

#endif