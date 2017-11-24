#include <iostream>
#include <vector>
class Solution {
public:
    int maxProduct(std::vector<std::string>& words) {
        std::vector<int> flg;
        for (std::vector<int>::size_type i = 0; i < words.size(); ++i) {
            int tflg = 0;
            for (std::string::size_type j = 0; j < words[i].length(); ++j) {
                tflg |= (1 << (words[i][j] - 'a'));
            }
            flg.push_back(tflg);
        }
        int ans = 0;
        for (std::vector<int>::size_type i = 0; i < flg.size(); ++i) {
            for (std::vector<int>::size_type j = i + 1; j < flg.size(); ++j) {
                if (!(flg[i] & flg[j])) {
                    int tans = words[i].length() * words[j].length();
                    if (tans > ans) {
                        ans = tans;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}