//
// Created by dingmao on 2022/2/15.
//

#include "lc_2172.h"
#include <gtest/gtest.h>

TEST(LCTest, lc_2172)
{
    vector<int> nums = { 1,2,3,4,5,6 };
    int numSlots = 3;

    auto *s = new Solution();
    int result = s->maximumANDSum(nums, numSlots);
    cout << result << endl;
}