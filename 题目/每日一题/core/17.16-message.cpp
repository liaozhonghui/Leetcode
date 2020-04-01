#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int massage(vector<int> &nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return fmax(dp[len - 1][0], dp[len - 1][1]);
    }
};
int main() {
    Solution solution;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    int res = solution.massage(nums);
    cout << "res: " << res << endl;
}