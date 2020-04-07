#include <vector>
using namespace std;
class Solution {
   public:
    int moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i == j)
                    j++;
                else
                    nums[j++] = nums[i], nums[i] = 0;
            }
        }
    }
};

int a[10];
int current = 5;
bool insertOp(int index, int e) {
    int temp = a[index];
    a[current + 1] = temp;
    a[index] = e;
    return true;
}