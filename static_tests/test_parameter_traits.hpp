#ifndef TEST_PARAMETER_TRAITS_HPP
#define TEST_PARAMETER_TRAITS_HPP

#include <utils/parametertrait.hpp>

static_assert(std::is_same<int, utils::parameter_trait<int>::type>::value, "utils::parameter_trait<int>::type != int");
static_assert(std::is_same<const int, utils::const_parameter_trait<int>::type>::value, "utils::const_parameter_trait<int>::type != const int");
static_assert(std::is_same<int&, utils::parameter_trait<int&>::type>::value, "utils::parameter_trait<int&>::type != int&");
//static_assert(std::is_same<const int&, utils::const_parameter_trait<int&>::type>::value, "utils::const_parameter_trait<int&>::type != const int&");

class Test;
static_assert(std::is_same<Test&, utils::parameter_trait<Test>::type>::value, "utils::parameter_trait<Test>::type != Test&");
static_assert(std::is_same<const Test&, utils::const_parameter_trait<Test>::type>::value, "utils::const_parameter_trait<Test>::type != const Test&");
static_assert(std::is_same<Test*, utils::parameter_trait<Test*>::type>::value, "utils::parameter_trait<Test*>::type != Test*");
static_assert(std::is_same<Test* const, utils::const_parameter_trait<Test*>::type>::value, "utils::const_parameter_trait<Test*>::type != const Test*");

#endif // TEST_PARAMETER_TRAITS_HPP
