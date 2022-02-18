//
// Created by dingmao on 2022/2/16.
//

#include "lc_759.h"
#include <gtest/gtest.h>

TEST(LCTest, lc_759) /* NOLINT */
{
//    vector<vector<Interval>> schedule = {{Interval(1,2),Interval(5,6)},
//                                         {Interval(1,3)},
//                                         {Interval(4,10)}};

    vector<vector<Interval>> schedule = {{Interval(1,3),Interval(6,7)},
                                         {Interval(2,4)},
                                         {Interval(2,5),Interval(9,12)}};

    auto* s = new Solution();
    const vector<Interval> &vector = s->employeeFreeTime(schedule);
    std::cout << "[";
    int idx = 1;
    for (const auto& v : vector )
    {
        std::cout << "[" << v.start << ", " << v.end << "]";
        if(idx < vector.size()) {
            std::cout << "," ;
            idx++;
        }
    }
    std::cout << "]" << std::endl;
}