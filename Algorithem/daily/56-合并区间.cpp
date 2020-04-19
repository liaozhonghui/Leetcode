#include <algorithm>
#include <vector>
using namespace std;

/**
 *
 */
class Soluition {
   public:
    vector<vector<int>> merge(vector<vector<int>> intervals) {
        int n = intervals.size();
        if (n = 0)
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            int L = intervals[i][0];
            int R = intervals[i][1];
            if (res.size() > 0 && res.back()[1] < L) {
                res.push_back({L, R});
            } else {
                res.back()[1] = max(res.back()[1], R);
            }
        }
        return res;
    }
};
