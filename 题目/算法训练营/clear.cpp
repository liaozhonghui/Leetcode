#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    string clear(string s)
    {
        string res;
        stack<char> st;
        int count = 0;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == st.top())
            {
                count++;
                st.push(s[i]);
            }
            else if (count >= 2)
            {
                while (count > 0)
                    st.pop();
                count = 0;
            }
            else
            {
                count = 0;
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
    // 3指针法
    string clear1(string s)
    {
        int len = s.length();
        if (len < 3)
            return s;
        int i = 0, j = 0, k = 1;
        int count = 0;
        vector<char> res;
        for (; k < len - 1; k++)
        {
            if (s[k] != s[j])
            {
                j++;
            }
            else
            {
                if (s[k] = s[k + 1])
                {
                }
                else
                {
                    j++;
                }
            }
        }
    }
};
int main()
{
    string s = "abcddddccabc";
    Solution solution;
    string clearS = solution.clear(s);
    cout << "res:" << clearS << endl;
}