#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
    int liner[80000] = {-1};
public:
    /* // 计数法
    int minIncrementUnique(vector<int> &A)
    {
    }
    // 排序法
    int minIncrementUnique(vector<int> &A)
    {
    } */
    // 线性探测法+动态压缩
    
    int minIncrementUnique(vector<int> &A)
    {
        int res = 0;
        for (int a : A)
        {
            int pos = findPos(a);
            res += pos - a;
        }
        return res;
    };
    int findPos(int a)
    {
        if (liner[a] == -1)
        {
            liner[a] = a;
            return a;
        }
        else
        {
            int b = findPos(a + 1);
            liner[a] = b;
            return b;
        }
    };
};

int main()
{
    Solution solution;
    vector<int> h({3, 2, 1, 2, 1, 7});
    int res = solution.minIncrementUnique(h);
    cout << "res:" << res << endl;
}
