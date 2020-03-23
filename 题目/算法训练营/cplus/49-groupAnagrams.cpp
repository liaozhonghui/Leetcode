class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        /**
         * 1. 解法：使用sort进行字符串排序，并且使用hashmap记录下标
        */
        unordered_map<string, int> ma;
        vector<vector<string>> res;
        int index = 1;
        string e;
        for (string s : strs)
        {
            e = s;
            sort(e.begin(), e.end());
            if (!ma[e])
            {
                ma[e] = index++;
                res.push_back(vector<string>());
            }
            res[ma[e] - 1].push_back(s);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        /**
         * 使用两层map记录，第二层map记录其中的字符串数组
        */
        map<map<char, int>, vector<string>> ma;
        vector<vector<string>> res;
        for (string s : strs)
        {
            map<char, int> tmp;
            for (int i = 0; i < s.length(); i++)
            {
                tmp[s[i]]++;
            }
            ma[tmp].push_back(s);
        }
        for (map<map<char, int>, vector<string>>::iterator it = ma.begin(); it != ma.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};