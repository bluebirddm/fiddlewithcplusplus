//
// Created by dingmao on 2021/12/2.
//

#include "ceil_test.h"
#include <gtest/gtest.h>

TEST(HelloTest, CeilTest) {
    printf("%f\n", 1.0 / 3 + 1.0 / 3 + 1.0 / 3 + 8.0);

    printf("%f\n", ceil(8.0 + 1.0 / 3 + 1.0 / 3 + 1.0 / 3));

    printf("%0.15f\n",  8.0 + 1.0 / 3 + 1.0 / 3 + 1.0 / 3);

    double eps = 1e-8;

    printf("%f\n", ceil(8.0 + 1.0 / 3 + 1.0 / 3 + 1.0 / 3  - eps ));
}