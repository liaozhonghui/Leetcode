#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    string clear(string s) {
        stack<char> st1;
        stack<char> st2;
        int CLEAR_NUM = 3;
        int count = 1;
        int len = s.length();
        for (int i = 0; i < s.length(); i++) {
            if (st1.empty() || (st1.top() != s[i] && count == 1)) {
                st1.push(s[i]);
            } else {
                if (!st1.empty() && st1.top() == s[i]) {
                    count++;
                    st2.push(s[i]);
                }
                if (!st2.empty() && st1.top() != s[i]) {
                    if (count >= CLEAR_NUM) {
                        while (!st2.empty())
                            st2.pop();
                        st1.pop();
                        i--;
                        len -= count;
                        count = 1;
                    } else {
                        while (!st2.empty()) {
                            st1.push(st2.top());
                            st2.pop();
                        }
                        count = 1;
                    }
                }
            }
        }
        char* ch = new char[len];
        for (int i = 0; !st1.empty() && i < len; i++) {
            ch[len - i] = st1.top();
            st1.pop();
        }
        return string(ch);
    }
};
int main() {
    string s = "abcddddccabc";
    Solution solution;
    string clearS = solution.clear(s);
    cout << "res:" << clearS << endl;
}