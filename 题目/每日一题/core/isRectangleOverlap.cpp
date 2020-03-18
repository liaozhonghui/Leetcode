class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        //解法1：通过取反进行求解,上下左右侧
        return !(rec1[1] >= rec2[3] ||
                 rec1[3] <= rec2[1] ||
                 rec1[2] <= rec2[0] ||
                 rec1[0] >= rec2[2]);
    }
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        //解法2：直接获取重叠部分
        return max(rec1[0], rec2[0])) < min(rec1[2], rec2[2]) &&
               max(rec1[1], rec2[1]) < min(rec1[3], rec2[3];
    }
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        return rec1[0] < rec2[2] && rec1[2] > rec2[0] && rec1[1] < rec2[3] && rec1[3] > rec2[1];
    }
};
int main()
{
    int a[] = {0, 0, 2, 2};
    int b[] = {1, 1, 3, 3};
}