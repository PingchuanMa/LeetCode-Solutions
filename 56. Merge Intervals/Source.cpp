#include <algorithm>
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
    static bool compare(Interval &a, Interval &b) { return a.start < b.start; }
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() == 0) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> ret;
        int start = intervals[0].start, end = intervals[0].end;
        for (auto interval : intervals) {
            if (interval.start > end) {
                ret.push_back(*(new Interval(start, end)));
                start = interval.start;
                end = interval.end;
            } else if (interval.end > end) {
                end = interval.end;
            }
        }
        ret.push_back(*(new Interval(start, end)));
        return ret;
    }
};
