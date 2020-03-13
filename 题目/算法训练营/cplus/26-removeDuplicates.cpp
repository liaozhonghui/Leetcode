#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 1)
            return len;
        int i = 0, j = 1;
        while (i < j && j < len)
        {
            while (nums[i] == nums[j] && j < len)
                j++;
            if ((j - i) > 1)
            {
                nums[++i] = nums[j++];
            }
            else
            {
                i++;
                j++;
            }
        }
        return i + 1;
    }
};
int main()
{
    Solution solution;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    int res = solution.removeDuplicates(nums);
    cout << "结果:" << res << endl;
}