//Solution #1 (Time Limit Exceeded)

//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		if (m == 1 || n == 1) { return 1; }
//		else if (m < 1 || n < 1) { return 0; }
//		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
//	}
//};

//Solution #2
#include <vector>
class Solution {
public:
	int uniquePaths(int m, int n) {
		std::vector<std::vector<int> > N_path(m, std::vector<int>(n, 1));
		for (size_t i = 1; i < m; ++i) {
			for (size_t j = 1; j < n; ++j) {
				N_path[i][j] = N_path[i - 1][j] + N_path[i][j - 1];
			}
		}
		return N_path[m - 1][n - 1];
	}
};