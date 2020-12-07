#include <queue>
#include <vector>
using namespace std;

/**
 * clarification:01矩阵
 * solutions:
 * 1.
 * 采用BFS广度优先遍历，时间复杂度为O(n*m)(寻找0的过程用了两层循环-复杂度为O(n)，BFS遍历获取的时间复杂度为O(n*m)),空间复杂度为O(m*n)
 */
class Solution {
   private:
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        vector<vector<int>> visited(n, vector<int>(m));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!matrix[i][j]) {
                    visited[i][j] = 1;
                    q.push(make_pair(i, j));
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    !visited[nx][ny]) {
                    res[nx][ny] = res[x][y] + 1;
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                }
            }
        }
        return res;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = matrix[i][j] == 0 ? 0 : 10000;
            }
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if (j - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        };
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i + 1 < n)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                if (j + 1 < m)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        };
        return dp;
    }
};