class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        // Count numbers divisible by each d
        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d)
                cnt[d] += freq[m];
        }

        vector<long long> exact(mx + 1, 0);

        // Inclusion-exclusion
        for (int d = mx; d >= 1; d--) {
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;
            for (int m = d + d; m <= mx; m += d)
                exact[d] -= exact[m];
        }

        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;
        for (long long k : queries) {
            int g = upper_bound(prefix.begin(), prefix.end(), k) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};