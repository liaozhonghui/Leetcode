#include <iostream>
using namespace std;
#include <math.h>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        depth(root);
        return ans;
    }
    int depth(TreeNode* rt)
    {
        if (rt == NULL)
            return 0;
        int L = depth(rt->left);
        int R = depth(rt->right);
        ans = max(ans, (L + R));
        return max(L, R) + 1;
    }
};
