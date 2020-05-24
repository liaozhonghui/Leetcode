#include <vector>
using namespace std;
class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int pos = k % nums.size();
        int previous = nums[nums.size() - 1];
        for (int i = 0; i < pos; i++) {
            for (int j = 0; j < nums.size(); j++) {
                int temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
};