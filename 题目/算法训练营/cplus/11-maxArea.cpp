#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/**
 * 题目描述：
 * 切题：n>=2
*/
class Solution
{
public:
    /**
     * 解法1：暴力解法，计算次数为c(n,2);
     * 时间复杂度为O(n2)
     * 空间复杂度为O(1)
    */
    int maxArea(vector<int> &height)
    {
        int result = 0;
        int heightSize = height.size();
        for (int i = 0; i < heightSize; i++)
        {
            for (int j = i + 1; j < heightSize; j++)
            {
                int minHeight = min(height[i], height[j]);
                result = max(result, minHeight * (j - i));
            }
        }
        return result;
    }
    /**
     * 解法2：双指针法: 起点指针a(0)与末尾指针a(n-1),比较出最小的数据H，二层遍历小于等于H的，指针向内收缩 ,结束条件，两个指针相遇
     * 时间复杂度为O(n)
     * 空间复杂度为O(1)
    */
    int maxArea1(vector<int> &height)
    {
        int result = 0;
        int size = height.size();
        int i = 0, j = size - 1;
        while (i < j)
        {
            int minHeight = fmin(height[i], height[j]);
            result = fmax(result, (j - i) * minHeight);
            while (height[i] <= minHeight && i < j)
                i++;
            while (height[j] <= minHeight && i < j)
                j--;
        }
        return result;
    };
    int maxArea2(vector<int> &height)
    {
        int l = 0;
        int h = height.size() - 1;
        int max = 0;

        while (l < h)
        {
            int candidate = (h - l) * (height[l] < height[h] ? height[l++] : height[h--]);
            max = max > candidate ? max : candidate;
        }
        return max;
    }
};

int main()
{
    // 添加测试用例；

    vector<int> height;
    height.push_back(1);
    height.push_back(1);
    height.push_back(1);
    height.push_back(1);
    height.push_back(1);
    height.push_back(1);
    Solution solutionInst;
    int maxAreaRes = solutionInst.maxArea1(height);
    cout << "计算结果：" << maxAreaRes << endl;
};
