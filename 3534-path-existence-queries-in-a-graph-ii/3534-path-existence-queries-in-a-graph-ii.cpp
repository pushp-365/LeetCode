class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);

        sort(ord.begin(), ord.end(),
             [&](int a, int b) {
                 if (nums[a] == nums[b]) return a < b;
                 return nums[a] < nums[b];
             });

        const int LOG = 17;
        vector<vector<int>> fa(n, vector<int>(LOG));

        int l = 0;
        for (int i = 0; i < n; i++) {
            while (nums[ord[i]] - nums[ord[l]] > maxDiff)
                l++;

            fa[i][0] = l;

            for (int j = 1; j < LOG; j++)
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[ord[i]] = i;

        vector<int> ans;

        for (auto &q : queries) {
            int a = pos[q[0]];
            int b = pos[q[1]];

            if (a < b) swap(a, b);

            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (fa[a][k] > b) {
                    a = fa[a][k];
                    steps += 1 << k;
                }
            }

            if (fa[a][0] > b) {
                ans.push_back(-1);
            } else {
                if (a != b) steps++;
                ans.push_back(steps);
            }
        }

        return ans;
    }
};