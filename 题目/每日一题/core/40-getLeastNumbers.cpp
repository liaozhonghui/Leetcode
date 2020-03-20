#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        int len = arr.size();
        for (int i = 0; i < len; i++)
        {

        }
        return new vector<int>(arr[0],arr[k-1]);
    }
};