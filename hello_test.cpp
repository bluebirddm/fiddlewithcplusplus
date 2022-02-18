//
// Created by dingmao on 2021/12/7.
//
#include "hello_test.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) /* NOLINT */
{
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);

    ////////////////////////////////////

    string name = "uncharted";
    const string* ps1 = &name; // 指向常量
//    *ps1 = "spiderman";        // 错误，不允许修改


    string* const ps2 = &name;  // 指向变量，但指针本身不能被修改
    *ps2 = "spiderman";        // 正确，允许修改

    ////////////////////////////////////

    loop_test();

}


