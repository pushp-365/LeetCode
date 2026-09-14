1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        int n = temperatures.size();
5        vector<int> ans(n, 0);
6
7        stack<pair<int, int>> st;
8
9        for (int i = n - 1; i >= 0; i--) {
10            while (!st.empty() && st.top().first <= temperatures[i]) {
11                st.pop();
12            }
13
14            if (!st.empty()) {
15                int val = st.top().second;
16                ans[i] = val - i;
17            }
18
19            st.push({temperatures[i], i});
20        }
21
22        return ans;
23    }
24};