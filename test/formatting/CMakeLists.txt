# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

if(NOT CLANG_FORMAT)
    message(WARNING "clang-format not found - target 'test.format' will be unavailable.")
    return()
endif()

test_formatting(test.formatting Metal ${METAL_INCLUDE_DIR})
