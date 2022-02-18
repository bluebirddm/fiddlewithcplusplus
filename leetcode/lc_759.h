//
// Created by dingmao on 2022/2/16.
//

#ifndef DEMO_LC_759_H
#define DEMO_LC_759_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

//https://yasenh.github.io/post/cpp-diary-1-emplace_back/

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

// Author: Huahua
// Running time: 81 ms
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> all;
        for (const auto intervals : schedule)
            all.insert(all.end(), intervals.begin(), intervals.end());
        std::sort(all.begin(), all.end(),
                  [](const Interval& a, const Interval& b){
                      return a.start < b.start;
                  });
        vector<Interval> ans;
        int end = all.front().end;
        for (const Interval& busy : all) {
            if (busy.start > end)
                ans.emplace_back(end, busy.start);
            end = max(end, busy.end);
        }
        return ans;
    }

    vector<Interval> employeeFreeTimeV2(vector<vector<Interval>> schedule) {
        int l = INT_MAX;
        vector<Interval> v;
        for(auto& s: schedule)
            for(auto& i : s)
            {
                v.push_back(i);
                l = min(l, i.end);
            }
        sort(v.begin(), v.end(), [&](auto& a, auto& b){
            if(a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });
        vector<Interval> ans;
        for(int i = 0; i < v.size(); ++i)
        {
            if(l < v[i].start)
                ans.push_back(Interval(l, v[i].start));
            l = max(l, v[i].end);
        }
        return ans;
    }

};


#endif //DEMO_LC_759_H
