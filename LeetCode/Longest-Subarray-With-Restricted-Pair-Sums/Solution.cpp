1class Solution {
2public:
3    int maxSubarray(vector<int>& nums) {
4        int n = nums.size();
5        unordered_map<int, int> freq;
6        int l = 0;
7        int ans = 0;
8        auto valid = [&](int x) {
9            for (auto &[a, cnt] : freq) {
10                if (freq.count(a + x))
11                    return false;
12                int b = x - a;
13                if (b > 0 && freq.count(b)) {
14                    if (a != b || cnt >= 2)
15                        return false;
16                }
17            }
18            return true;
19        };
20        for (int r = 0; r < n; r++) {
21            while (!valid(nums[r])) {
22                freq[nums[l]]--;
23                if (freq[nums[l]] == 0)
24                    freq.erase(nums[l]);
25                l++;
26            }
27            freq[nums[r]]++;
28            ans = max(ans, r - l + 1);
29        }
30        return ans;
31    }
32};