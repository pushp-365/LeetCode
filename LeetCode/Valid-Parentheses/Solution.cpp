1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5
6        for (char ch : s) {
7
8            if (ch == '(' || ch == '{' || ch == '[') {
9                st.push(ch);
10            }
11            else {
12                if (st.empty())
13                    return false;
14
15                if ((ch == ')' && st.top() != '(') ||
16                    (ch == '}' && st.top() != '{') ||
17                    (ch == ']' && st.top() != '['))
18                    return false;
19
20                st.pop();
21            }
22        }
23
24        return st.empty();
25    }
26};