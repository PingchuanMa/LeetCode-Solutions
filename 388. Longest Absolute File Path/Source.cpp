#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        input += '\n';
        stack<int> s;
        int sum = 0, temp = 0, max = 0, indent = 0, spaces = 0;
        bool isFile = false, indenting = true;
        for (char c : input) {
            if (c == '\n') {
                if (isFile) {
                    sum += temp;
                    if (sum > max) {
                        max = sum;
                    }
                } else {
                    sum += ++temp;
                }
                s.push(temp);
                temp = 0;
                indent = 0;
                isFile = false;
                indenting = true;
            } else if (c == '\t') {
                ++indent;
            } else {
                if (indenting) {
                    if (c == ' ') {
                        if (++spaces == 4) {
                            ++indent;
                            spaces = 0;
                        }
                        continue;
                    }
                    if (s.size() < indent) {
                        temp += (indent - s.size()) * 4;
                    } else {
                        for (int i = s.size(); i > indent; --i) {
                            sum -= s.top();
                            s.pop();
                        }
                    }
                    indenting = false;
                }
                if (c == '.') {
                    isFile = true;
                }
                ++temp;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    cout << s.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") << endl;
    return 0;
}
