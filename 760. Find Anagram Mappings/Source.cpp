#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> index;
        vector<int> ret(A.size());
        for (int i = 0; i < B.size(); ++i) {
            index[B[i]] = i;
        }
        for (int i = 0; i < A.size(); ++i) {
            ret[i] = index[A[i]];
        }
        return ret;
    }
};
