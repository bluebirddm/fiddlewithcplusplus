//
// Created by dingmao on 2022/2/17.
//

#include "lc_1157.h"
#include <gtest/gtest.h>

TEST(LCTest, lc_1157) /* NOLINT */
{
    vector<int> arr = {1,1,2,2,1,1};
    auto* obj = new MajorityChecker(arr);
    int param_1 = obj->query(0, 5, 4);
    std::cout << param_1 << ", ";
    int param_2 = obj->query(0, 3, 3);
    std::cout << param_2 << ", ";
    int param_3 = obj->query(2, 3, 2);
    std::cout << param_3 << std::endl;
}