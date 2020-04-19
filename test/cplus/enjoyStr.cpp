#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int index;
    char val;
    Node(int x, char y) : val(y), index(x){};
};
bool cmp(const Node& n1, const Node& n2) {
    if (n1.index > n2.index) return true;
    return false;
};
class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        vector<Node> res;
        res.push_back(Node(a, 'a'));
        res.push_back(Node(b, 'b'));
        res.push_back(Node(c, 'c'));
        sort(res.begin(), res.end(), cmp);
        int inter = res[0].index / 2;
        int max   = res[0].index;
        int mid   = res[1].index;
        int min   = res[2].index;
        int i = 1, j = 1, k = 1;
        int len = 0;
        string s;
        while (i < inter) {
            s.push_back(res[0].val);
            s.push_back(res[0].val);
            s.append(" ");
            i++;
        }
        while (j <= mid && (3 * j - 1) < s.length()) {
            s[3 * j - 1] = res[1].val;
            j++;
        }
        while (k <= min && (3 * j - 1) < s.length() && (3 * (j - 1 + k) - 1) < s.length()) {
            s[3 * (j - 1 + k) - 1] = res[2].val;
            k++;
        }
        len = 2 + 3 * (j - 1) + 3 * (k - 1);
        return s.substr(0, len);
    }
};

int main() {
    Solution solution = Solution();
    solution.longestDiverseString(1, 1, 7);
}