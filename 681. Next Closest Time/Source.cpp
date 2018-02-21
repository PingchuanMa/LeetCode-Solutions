#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <iomanip>
using namespace std;
class Solution {
public:
    string nextClosestTime(string time) {
        int candidates[] = {
            time[0] - '0',
            time[1] - '0',
            time[3] - '0',
            time[4] - '0'
        };
        int baseline = (candidates[0] * 10 + candidates[1]) * 60 + candidates[2] * 10 + candidates[3];
        int ret = baseline, minDelta = 24 * 60;
        for (int i : candidates) {
            for (int j : candidates) {
                for (int k : candidates) {
                    for (int l : candidates) {
                        int tmp = 0;
                        if ((tmp = str2delta(i * 10 + j, k * 10 + l, baseline)) < minDelta) {
                            minDelta = tmp;
                            ret = (i * 10 + j) * 60 + k * 10 + l;
                        }
                    }
                }
            }
        }
        stringstream ss;
        ss << setfill('0') << setw(2) << ret / 60 << ":" << setw(2) << ret % 60;
        return ss.str();
    }
    int str2delta(int hour, int minute, int baseline) {
        if (hour > 23 || minute > 59) {
            return 24 * 60;
        }
        int ret = hour * 60 + minute - baseline;
        return ret > 0 ? ret : (ret + 24 * 60);
    }
};
