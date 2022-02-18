//
// Created by dingmao on 2022/2/11.
//

#include "lc_2152.h"
#include <gtest/gtest.h>

TEST(LCTest, lc_2152) {

    vector<vector<int>> points= {{0,1},{2,3},{4,5},{4,3}};
    auto *s = new Solution();
    auto result = s->minimumLines(points);
    std::cout << "result = " << result << std::endl;

//    const int bit_size = 3;
//    int total = 0;
//    for (int state = 0; state < (1<< bit_size); state++){
//        int i = 0;
//        int temp = state;
//        while( i < bit_size) {
//            std::cout << temp%2;
//            temp = temp/2;
//            i++;
//        }
//        total++;
//        std::cout << std::endl;
//    }
//    std::cout << "total = " << total << std::endl;
}