//
// Created by dingmao on 2022/2/9.
//

#include "lc_2167.h"
#include <gtest/gtest.h>

using namespace std;

TEST(LCTest, lc_1267)
{

    string testCase = "1100101";
    auto *s = new Solution();
    auto result = s->minimumTime(testCase);
    std::cout << result << std::endl;

}