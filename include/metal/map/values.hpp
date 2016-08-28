// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_VALUES_HPP
#define METAL_MAP_VALUES_HPP

#include <metal/config.hpp>

#include <metal/map/map.hpp>
#include <metal/pair/second.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup map
    ///
    /// ### Description
    /// Returns a \list of values contained in a \map.
    ///
    /// ### Usage
    /// For any \map `map`
    /// \code
    ///     using result = metal::values<map>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `map` associates keys `key_1, ..., key_n` to values
    ///     `val_1, ..., val_n`, then
    ///     \code
    ///         using result = metal::list<val_1, ..., val_n>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet map.cpp values
    ///
    /// ### See Also
    /// \see map, keys
    template<typename seq>
    using values = metal::if_<
        metal::is_map<seq>,
        metal::transform<metal::lambda<metal::second>, seq>
    >;
}

#endif
