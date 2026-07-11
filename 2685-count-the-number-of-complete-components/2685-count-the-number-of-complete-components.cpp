class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int nodes = 0;
            int degreeSum = 0;

            stack<int> st;
            st.push(i);
            vis[i] = 1;

            while (!st.empty()) {
                int u = st.top();
                st.pop();

                nodes++;
                degreeSum += adj[u].size();

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        st.push(v);
                    }
                }
            }

            if (degreeSum == nodes * (nodes - 1))
                ans++;
        }

        return ans;
    }
};