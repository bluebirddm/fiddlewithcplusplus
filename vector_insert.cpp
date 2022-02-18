//
// Created by dingmao on 2021/12/2.
//

#include "vector_insert.h"

#include <bits/stdc++.h>

#include <gtest/gtest.h>

//using namespace std;

//int vector_insert::test_vector_insert()
TEST(HelloTest, VectorInsert)
{
    using namespace std;

    // initialising the vector
    vector<int> vec1 = { 10, 20, 30, 40 };
    vector<int> vec2;

    // inserts at the beginning of vec2
    vec2.insert(vec2.begin(), vec1.begin(), vec1.end());

    vec2.insert(vec2.begin(), 0);

    cout << "The vector2 elements are: ";
    for (auto it = vec2.begin(); it != vec2.end(); ++it)
        cout << *it << " ";

    EXPECT_FALSE(false);
}