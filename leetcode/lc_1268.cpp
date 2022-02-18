//
// Created by dingmao on 2022/1/30.
//

#include "lc_1268.h"
#include <gtest/gtest.h>

TEST(LCTest, lc_1268)
{
    vector<string> products = { "mobile","mouse","moneypot","monitor","mousepad" };
    auto *s = new Solution();
    auto result = s->suggestedProducts(products, "mouse");

    for ( const auto& v : result )
    {
        for ( const string& x : v ) std::cout << x << ' ';
        std::cout << std::endl;
    }
}