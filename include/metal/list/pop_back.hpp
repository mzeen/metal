// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_POP_BACK_HPP
#define METAL_LIST_POP_BACK_HPP

#include <metal/list/size.hpp>
#include <metal/list/range.hpp>
#include <metal/number/sub.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename n = number<1>>
    using pop_back = metal::range<
        seq,
        metal::number<0>,
        metal::sub<metal::size<seq>, n>
    >;
}

#endif
