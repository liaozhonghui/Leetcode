#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int result = 0;
        int heightSize = int(height.size());
        for (int i = 0; i < heightSize; i++)
        {
            for (int j = i + 1; j < heightSize; j++)
            {
                int min = height[i] < height[j] ? height[i] : height[j];
                int temp = (j - i) * min;
                if (temp > result)
                    result = temp;
            }
        }
        return result;
    }
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
};

int main()
{
    // 添加测试用例；

    vector<int> height;
    height.push_back(1);
    height.push_back(7);
    height.push_back(4);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(3);
    Solution solutionInst;
    int maxAreaRes = solutionInst.maxArea1(height);
    cout << "计算结果：" << maxAreaRes << endl;
};
