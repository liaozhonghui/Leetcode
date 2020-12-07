#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> tempMap;
        int majority = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            tempMap[nums[i]]++;
            if (majority <= tempMap[nums[i]])
            {
                majority = tempMap[nums[i]];
                result = nums[i];
            }
        }
        return result;
    }
};

int main()
{
}