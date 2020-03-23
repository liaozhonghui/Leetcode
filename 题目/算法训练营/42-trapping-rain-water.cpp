class Solution
{
public:
    int trap(vector<int> &height)
    {
        /**
          * 1. 定义返回值，
          * 2. 遍历每个元素
          * 3. 取该元素的左边最大值，和右边最大值
          * 4. 取出第三步的最小值，减去当前元素的高度就是该元素的接水量
         */
        int res = 0;
        int len = height.size();
        for (int i = 0; i < len - 1; i++)
        {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; j--)
                max_left = max(max_left, height[j]);
            for (int k = i; k < len; k++)
                max_right = max(max_right, height[k]);
            res += min(max_left, max_right) - height[i];
        }
        return res;
    }
    int trap(vector<int> &height)
    {
        int len = height.size();
        if (len <= 1)
            return 0;
        int res = 0;
        vector<int> max_left(len), max_right(len);
        max_left[0] = height[0];
        max_right[len - 1] = height[len - 1];
        for (int i = 1; i < len; i++)
        {
            max_left[i] = max(max_left[i - 1], height[i]);
        }
        for (int j = len - 2; j >= 0; j--)
        {
            max_right[j] = max(max_right[j + 1], height[j]);
        }
        for (int k = 0; k < len; k++)
        {
            res += min(max_left[k], max_right[k]) - height[k];
        }
        return res;
    }
    int trap(vector<int> &height)
    {
        int res = 0;
        int len = height.size();
        int max_left = 0, max_right = 0, i = 0, j = len - 1;
        while (i < j)
        {
            if (height[i] <= height[j])
            {
                if (height[i] >= max_left)
                    max_left = height[i];
                else
                    res += max_left - height[i];
                i++;
            }
            else
            {
                if (height[j] >= max_right)
                    max_right = height[j];
                else
                    res += max_right - height[j];
                j--;
            }
        }
        return res;
    }
    int trap(vector<int> &height)
    {
        int len = height.size();
        int res = 0, current = 0;
        stack<int> st;
        while (current < len)
        {
            while (!st.empty() && height[current] > height[st.top()])
            {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int d = current - st.top() - 1;
                int h = min(height[current], height[st.top()]) - height[top];
                res += d * h;
            }
            st.push(current++);
        }
        return res;
    }
};