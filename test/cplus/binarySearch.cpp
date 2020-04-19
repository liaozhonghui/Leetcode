#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums, int target) {
        return 0;
    }
    int findPos(vector<int>& nums) {
        if (nums.size() == 0) throw "数组长度为0";
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
int main() {
    Solution solution = Solution();
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int res = solution.findPos(nums);
    cout << "res:" << res << endl;
}