#include <iostream>
#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        bool merging = true;
        for (auto interval : intervals) {
            if (interval.end < newInterval.start) {
                result.push_back(interval);
            } else if (newInterval.end < interval.start) {
                if (merging) {
                    result.push_back(newInterval);
                    merging = false;
                }
                result.push_back(interval);
            } else if (interval.start < newInterval.start) {
                newInterval.start = interval.start;
                if (newInterval.end < interval.end) {
                    newInterval.end = interval.end;
                    result.push_back(newInterval);
                    merging = false;
                }
            } else if (newInterval.end < interval.end) {
                newInterval.end = interval.end;
                result.push_back(newInterval);
                merging = false;
            }
        }
        if (merging) {
            result.push_back(newInterval);
        }
        return result;
    }
};
