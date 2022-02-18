//
// Created by dingmao on 2022/2/17.
//

#include "lower_bound_upper_bound.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

//借助输出结果可以看出，upper_bound() 函数的功能和 lower_bound() 函数不同，前者查找的是大于目标值的元素，而后者查找的不小于（大于或者等于）目标值的元素。

TEST(BoundTest, lower_bound_upper_bound) /* NOLINT */ {

    vector<int> arr = {1,3,4,5,6,8};

    int i = lower_bound(arr.begin(), arr.end(), 2) - arr.begin(); //不小于
    std::cout << "2 lower_bound : " << i << std::endl;
    i = upper_bound(arr.begin(), arr.end(), 2) - arr.begin(); //大于
    std::cout << "2 upper_bound : " << i << std::endl;
    std::cout << "----------------------------" << std::endl;

    i = lower_bound(arr.begin(), arr.end(), 7) - arr.begin();
    std::cout << "7 lower_bound : " << i << std::endl;
    i = upper_bound(arr.begin(), arr.end(), 7) - arr.begin();
    std::cout << "7 upper_bound : " << i << std::endl;
    std::cout << "----------------------------" << std::endl;

    i = lower_bound(arr.begin(), arr.end(), 1) - arr.begin();
    std::cout << "1 lower_bound : " << i << std::endl;
    i = upper_bound(arr.begin(), arr.end(), 1) - arr.begin();
    std::cout << "1 upper_bound : " << i << std::endl;

}