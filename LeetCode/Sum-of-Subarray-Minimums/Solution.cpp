1class Solution {
2public:
3    int sumSubarrayMins(vector<int>& arr) {
4        int n = arr.size();
5        const int MOD = 1e9 + 7;
6
7        vector<int> PSE(n), NSE(n);
8        stack<int> st;
9
10        // PSE = Previous Smaller Element
11        for (int i = 0; i < n; i++) {
12            while (!st.empty() && arr[st.top()] > arr[i])
13                st.pop();
14
15            PSE[i] = st.empty() ? -1 : st.top();
16            st.push(i);
17        }
18
19        while (!st.empty()) st.pop();
20
21        // NSE = Next Smaller Element
22        for (int i = n - 1; i >= 0; i--) {
23            while (!st.empty() && arr[st.top()] >= arr[i])
24                st.pop();
25
26            NSE[i] = st.empty() ? n : st.top();
27            st.push(i);
28        }
29
30        long long ans = 0;
31
32        for (int i = 0; i < n; i++) {
33            long long left = i - PSE[i];
34            long long right = NSE[i] - i;
35
36            ans = (ans + (long long)arr[i] * left * right) % MOD;
37        }
38
39        return ans;
40    }
41};