#include <string>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
      int longestPalindrome(string s)
    {
        // 1. 遍历s，使用map存储每个字母出现的个数
        // 2. 遍历s, 逐个加上res回文字符串长度
        // res计算方法：奇数个数的字母放/2 *2个，只要存在一个奇数个数的字符，中心点为一个
        // 偶数个数的字符放置/2个
        int res = 0;
        int len = s.length();
        int count[128] = {0};
        for (int i = 0; i < len; ++i)
        {
            count[s[i]]++;
        }
        for (int j = 0; j < len; j++)
        {
            res += count[s[j]] / 2 * 2;
            if ((res % 2 == 0) && (count[s[j]] % 2 == 1))
            {
                res++;
            }
            count[s[j]] = 0;
        }
        return res;
    }
    int longestPalindrome1(string s)
    {
        int res = 0;
        int len = s.length();
        unordered_map<char, int> m;
        for (int i = 0; i < len; ++i)
        {
            m[s[i]]++;
        }
        for (int j = 0; j < len; j++)
        {
            res += m[s[j]] / 2 * 2;
            m[s[j]] = 0;
        }
        return res + (res < len);
    }
    int longestPalindrome(string s)
    {
        if (s.length() == 0)
            return 0;
        set<char> hs;
        for (int i = 0; i < s.length(); i++)
        {
            if (hs.find(s[i]) != hs.end())
            {
                hs.erase(s[i]);
            }
            else
            {
                hs.insert(s[i]);
            }
        }
        int odd = hs.size();
        return s.length() - (odd == 0 ? 0 : odd - 1);
    }
};
int main()
{
    Solution solution;
    string a = "abccccdd";
    int count = solution.longestPalindrome(a);
    cout << "count:%d" << count << endl;
}
