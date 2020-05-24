#include <iostream>
using namespace std;
#include <math.h>
class Solution
{
public:
    bool check(string t, string s)
    {
        string temp = "";
        for (int j = 0; j < s.length(); j = j + t.length())
            temp += t;
        return s == temp;
    }
    string gcdOfStrings(string str1, string str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();
        for (int i = min(len1, len2); i >= 1; i--)
        {
            if (len1 % i == 0 && len2 % i == 0)
            {
                string res = str1.substr(0, i);
                if (check(res, str1) && check(res, str2))
                    return res;
            }
        }
        return "";
    }
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";
        int len1 = str1.length();
        int len2 = str2.length();
        for (int i = min(len1, len2); i >= 1; i--)
        {
            if (len1 % i == 0 && len2 % i == 0)
            {
                return str1.substr(0, i);
            }
        }
        return "";
    }
};