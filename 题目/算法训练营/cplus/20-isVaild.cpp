#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isVaild(string s)
    {
        /**
         * 1. 存放符号匹配Map
         * 2. 构造堆栈，左括号入队，右括号判断栈顶是否是匹配的括号，不是则返回false
         * 3. 第2步中如果是匹配的括号，将左括号弹出
         * 
        */
        unordered_map<char, char> m{{'{', '}'}, {'(', ')'}, {'[', ']'}};
        stack<char> st;
        for (char c : s)
        {
            if (m.find(c) != m.end())
            {
                st.push(c);
            }
            else if (!st.empty() && m[st.top()] == c)
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }
    bool isVaild(string s)
    {
        if (s.length() & 1 == 1)
            return false;
        stack<char> st;
        for (char c : s)
        {
            switch (c)
            {
            case '(':
                st.push(')');
                break;
            case '{':
                st.push('}');
                break;
            case '[':
                st.push(']');
                break;
            case ')':
            case '}':
            case ']':
                if (!st.empty() && st.top() == c)
                {
                    st.pop();
                    break;
                }
                else
                {
                    return false;
                }
            default:
                return false;
            }
        }
        return st.empty();
    }
};
int main() {}