#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> nonZeroNums;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nonZeroNums.push_back(i);
            }
        }
        for (int j = 0; j < nums.size(); j++)
        {
            nums[j] = j < nonZeroNums.size() ? nums[nonZeroNums[j]] : 0;
        }
    }
    void moveZeroes(vector<int> &nums)
    {
        int nonZeroNum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if (nonZeroNum == i)
                {
                    nonZeroNum++;
                }
                else
                {
                    nums[nonZeroNum++] = nums[i];
                    nums[i] = 0;
                }
            }
        }
    }
};