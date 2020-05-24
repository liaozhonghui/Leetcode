#include <vector>
using namespace std;
class Solution {
   public:
    // 借助辅助数组
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                res[j][matrix.size() - 1 - i] = matrix[i][j];
            }
        }
        matrix = res;
    }
    void rotate(vector<vector<int>>& matrix){
        
    }
};