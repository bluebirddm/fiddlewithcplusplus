//
// Created by dingmao on 2022/2/15.
//

#include "lc_2002.h"
#include <gtest/gtest.h>

TEST(LCTest, lc_2002) /* NOLINT */
{
    string input = "leetcodecom";
    auto *s = new Solution();
    auto result = s->maxProduct(input);

    std::cout << result << std::endl;
}