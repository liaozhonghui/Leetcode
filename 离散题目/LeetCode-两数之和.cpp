#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2)
            return {};
        unordered_map<int, int> imap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (imap.find(target - nums[i]) != imap.end() &&
                imap[target - nums[i]] != i)
                return vector<int>{imap[target - nums[i]], i};
            else
                imap[nums[i]] = i;
        }
        return {};
    }
};