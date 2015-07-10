// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/lambda.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;
using namespace metal::placeholders;

static_assert(std::is_same<lambda<void>::type, lambda<void>>{}, "");

static_assert(std::is_same<call_t<lambda<test::a0>>, test::a0>{}, "");
static_assert(std::is_same<call_t<lambda<test::a1>>, test::a1>{}, "");
static_assert(std::is_same<call_t<lambda<test::a2>>, test::a2>{}, "");
static_assert(std::is_same<call_t<lambda<test::a3>>, test::a3>{}, "");
static_assert(std::is_same<call_t<lambda<test::a4>>, test::a4>{}, "");
static_assert(std::is_same<call_t<lambda<test::a5>>, test::a5>{}, "");
static_assert(std::is_same<call_t<lambda<test::a6>>, test::a6>{}, "");
static_assert(std::is_same<call_t<lambda<test::a7>>, test::a7>{}, "");
static_assert(std::is_same<call_t<lambda<test::a9>>, test::a9>{}, "");
static_assert(std::is_same<call_t<lambda<test::a9>>, test::a9>{}, "");

static_assert(std::is_same<call_t<lambda<verbatim<test::a0>>>, test::a0>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::a1>>>, test::a1>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::a2>>>, test::a2>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::a3>>>, test::a3>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::a4>>>, test::a4>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::a5>>>, test::a5>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::a6>>>, test::a6>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::a7>>>, test::a7>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::a9>>>, test::a9>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::a9>>>, test::a9>{}, "");

static_assert(std::is_same<call_t<lambda<test::alias<>>>, test::alias<>>{}, "");
static_assert(not_<is_callable_t<lambda<test::empty<>>>>{}, "");
static_assert(not_<is_callable_t<lambda<test::call<>>>>{}, "");
static_assert(std::is_same<call_t<lambda<test::evaluable<>>>, test::evaluable<>::type>{}, "");
static_assert(std::is_same<call_t<lambda<test::evaluable_union<>>>, test::evaluable_union<>::type>{}, "");

static_assert(std::is_same<call_t<lambda<verbatim<test::alias<>>>>, test::alias<>>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::empty<>>>>, test::empty<>>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::call<>>>>, test::call<>>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::evaluable<>>>>, test::evaluable<>>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::evaluable_union<>>>>, test::evaluable_union<>>{}, "");

static_assert(std::is_same<call_t<lambda<test::wrapper>, void>, test::wrapper>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::wrapper>>, void>, test::wrapper>{}, "");
static_assert(std::is_same<call_t<lambda<protect<test::wrapper>>, void>, protect<test::wrapper>>{}, "");

static_assert(std::is_same<call_t<lambda<lambda<std::add_pointer<_1>>>, void>, lambda<void*>>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<lambda<std::add_pointer<_1>>>>, void>, lambda<std::add_pointer<_1>>>{}, "");
static_assert(std::is_same<call_t<lambda<protect<lambda<std::add_pointer<_1>>>>, void>, protect<lambda<std::add_pointer<_1>>>>{}, "");

static_assert(std::is_same<call_t<lambda<call<lambda<std::add_pointer<_1>>, void>>, void*>, void**>{}, "");
static_assert(std::is_same<call_t<lambda<call<verbatim<lambda<std::add_pointer<_1>>>, void>>, void*>, void*>{}, "");
static_assert(std::is_same<call_t<lambda<call<protect<lambda<std::add_pointer<_1>>>, void>>, void*>, void*>{}, "");

static_assert(not_<is_callable_t<lambda<_0>>>{}, "");
static_assert(std::is_same<call_t<lambda<_1>, test::a0, test::a1, test::a2, test::a3>, test::a0>{}, "");
static_assert(std::is_same<call_t<lambda<_2>, test::a0, test::a1, test::a2, test::a3>, test::a1>{}, "");
static_assert(std::is_same<call_t<lambda<_3>, test::a0, test::a1, test::a2, test::a3>, test::a2>{}, "");
static_assert(std::is_same<call_t<lambda<_4>, test::a0, test::a1, test::a2, test::a3>, test::a3>{}, "");

static_assert(std::is_same<call_t<lambda<verbatim<_0>>, test::a0, test::a1, test::a2, test::a3>, _0>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<_1>>, test::a0, test::a1, test::a2, test::a3>, _1>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<_2>>, test::a0, test::a1, test::a2, test::a3>, _2>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<_3>>, test::a0, test::a1, test::a2, test::a3>, _3>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<_4>>, test::a0, test::a1, test::a2, test::a3>, _4>{}, "");

static_assert(std::is_same<call_t<lambda<protect<_0>>, test::a0, test::a1, test::a2, test::a3>, protect<_0>>{}, "");
static_assert(std::is_same<call_t<lambda<protect<_1>>, test::a0, test::a1, test::a2, test::a3>, protect<_1>>{}, "");
static_assert(std::is_same<call_t<lambda<protect<_2>>, test::a0, test::a1, test::a2, test::a3>, protect<_2>>{}, "");
static_assert(std::is_same<call_t<lambda<protect<_3>>, test::a0, test::a1, test::a2, test::a3>, protect<_3>>{}, "");
static_assert(std::is_same<call_t<lambda<protect<_4>>, test::a0, test::a1, test::a2, test::a3>, protect<_4>>{}, "");

static_assert(std::is_same<call_t<lambda<test::wrap<_0>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, test::a2, test::a3>>{}, "");
static_assert(std::is_same<call_t<lambda<test::wrap<_1>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0>>{}, "");
static_assert(std::is_same<call_t<lambda<test::wrap<_1, _2>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1>>{}, "");
static_assert(std::is_same<call_t<lambda<test::wrap<_1, _2, _3>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, test::a2>>{}, "");
static_assert(std::is_same<call_t<lambda<test::wrap<_1, _2, _3, _4>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<test::a0, test::a1, test::a2, test::a3>>{}, "");

static_assert(std::is_same<call_t<lambda<verbatim<test::wrap<_0>>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<_0>>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::wrap<_1>>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<_1>>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::wrap<_1, _2>>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<_1, _2>>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::wrap<_1, _2, _3>>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<_1, _2, _3>>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<test::wrap<_1, _2, _3, _4>>>, test::a0, test::a1, test::a2, test::a3>, test::wrap<_1, _2, _3, _4>>{}, "");

static_assert(std::is_same<call_t<lambda<call<_1, _2>>, test::wrapper, void>, test::wrap<void>>{}, "");
static_assert(std::is_same<call_t<lambda<call<_1, _2, _1>>, test::wrapper, void>, test::wrap<void, test::wrapper>>{}, "");

static_assert(std::is_same<call_t<lambda<call<verbatim<_1>, _2>>, test::wrapper, void>, void>{}, "");
static_assert(std::is_same<call_t<lambda<call<verbatim<_1>, _2, _1>>, test::wrapper, void>, void>{}, "");

static_assert(std::is_same<call_t<lambda<call<protect<_1>, _2>>, test::wrapper, void>, void>{}, "");
static_assert(std::is_same<call_t<lambda<call<protect<_1>, _2, _1>>, test::wrapper, void>, void>{}, "");

static_assert(std::is_same<call_t<lambda<call<_0>>, test::wrapper, void>, test::wrap<void>>{}, "");
static_assert(std::is_same<call_t<lambda<call<_0, _0>>, test::wrapper, void>, test::wrap<void, test::wrapper, void>>{}, "");
static_assert(std::is_same<call_t<lambda<call<_0, _0, _0>>, test::wrapper, void>, test::wrap<void, test::wrapper, void, test::wrapper, void>>{}, "");

static_assert(std::is_same<call_t<lambda<call<_0, verbatim<_0>>>, test::wrapper, void>, test::wrap<void, _0>>{}, "");
static_assert(std::is_same<call_t<lambda<call<_0, verbatim<_0>, _0>>, test::wrapper, void>, test::wrap<void, _0, test::wrapper, void>>{}, "");

static_assert(std::is_same<call_t<lambda<call<_0, protect<_0>>>, test::wrapper, void>, test::wrap<void, protect<_0>>>{}, "");
static_assert(std::is_same<call_t<lambda<call<_0, protect<_0>, _0>>, test::wrapper, void>, test::wrap<void, protect<_0>, test::wrapper, void>>{}, "");

static_assert(std::is_same<call_t<lambda<lambda<_1>>, void>, lambda<void>>{}, "");
static_assert(std::is_same<call_t<lambda<verbatim<lambda<_1>>>, void>, lambda<_1>>{}, "");
static_assert(std::is_same<call_t<lambda<lambda<_1>>, verbatim<_1>>, lambda<verbatim<_1>>>{}, "");

static_assert(std::is_same<call_t<lambda<lambda<_1>>, void>, lambda<void>>{}, "");
static_assert(std::is_same<call_t<lambda<protect<lambda<_1>>>, void>, protect<lambda<_1>>>{}, "");
static_assert(std::is_same<call_t<lambda<lambda<_1>>, protect<_1>>, lambda<protect<_1>>>{}, "");

using chain = protect<lambda<call<lambda<_1>, call<lambda<_2>, _3>>>>;
static_assert(is_function<chain>{}, "");
static_assert(std::is_same<call_t<chain, std::add_pointer<_1>, std::add_const<_1>, void>, void const*>{}, "");
static_assert(std::is_same<call_t<chain, std::add_const<_1>, std::add_pointer<_1>, void>, void* const>{}, "");

using once = protect<lambda<call<chain, verbatim<_1>, _1, _2>>>;
static_assert(is_function<once>{}, "");
static_assert(std::is_same<call_t<once, std::add_pointer<_1>, void>, void*>{}, "");

using twice = protect<lambda<call<chain, _1, _1, _2>>>;
static_assert(is_function<twice>{}, "");
static_assert(std::is_same<call_t<twice, std::add_pointer<_1>, void>, void**>{}, "");

using thrice = protect<lambda<call<once, _1, call<twice, _1, _2>>>>;
static_assert(is_function<thrice>{}, "");
static_assert(std::is_same<call_t<thrice, std::add_pointer<_1>, void>, void***>{}, "");

using ptr2ptr2ptr = protect<lambda<call<thrice, verbatim<std::add_pointer<_1>>, _1>>>;
static_assert(is_function<ptr2ptr2ptr>{}, "");
static_assert(std::is_same<call_t<ptr2ptr2ptr, void>, void***>{}, "");

#include <metal/functional/identity.hpp>

using church_true = protect<lambda<lambda<identity<_1>>>>;
using church_false = protect<lambda<lambda<verbatim<_1>>>>;

using church_not = protect<lambda<call<call<_1, church_false>, church_true>>>;

static_assert(std::is_same<call_t<church_not, church_true>, church_false>{}, "");
static_assert(std::is_same<call_t<church_not, church_false>, church_true>{}, "");

using church_and = protect<lambda<bind<bind<_1, verbatim<_1>>, _1>>>;

static_assert(std::is_same<call_t<call_t<church_and, church_true>, church_true>, church_true>{}, "");
static_assert(std::is_same<call_t<call_t<church_and, church_true>, church_false>, church_false>{}, "");
static_assert(std::is_same<call_t<call_t<church_and, church_false>, church_true>, church_false>{}, "");
static_assert(std::is_same<call_t<call_t<church_and, church_false>, church_false>, church_false>{}, "");

using church_or = protect<lambda<bind<bind<_1, _1>, verbatim<_1>>>>;

static_assert(std::is_same<call_t<call_t<church_or, church_true>, church_true>, church_true>{}, "");
static_assert(std::is_same<call_t<call_t<church_or, church_true>, church_false>, church_true>{}, "");
static_assert(std::is_same<call_t<call_t<church_or, church_false>, church_true>, church_true>{}, "");
static_assert(std::is_same<call_t<call_t<church_or, church_false>, church_false>, church_false>{}, "");

using church_xor = protect<lambda<bind<bind<_1, verbatim<call<church_not, _1>>>, verbatim<_1>>>>;

static_assert(std::is_same<call_t<call_t<church_xor, church_true>, church_true>, church_false>{}, "");
static_assert(std::is_same<call_t<call_t<church_xor, church_true>, church_false>, church_true>{}, "");
static_assert(std::is_same<call_t<call_t<church_xor, church_false>, church_true>, church_true>{}, "");
static_assert(std::is_same<call_t<call_t<church_xor, church_false>, church_false>, church_false>{}, "");
