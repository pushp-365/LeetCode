1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int sum = 0;
5        int maxi = nums[0];
6
7        for (int i = 0; i < nums.size(); i++) {
8            sum += nums[i];
9
10            maxi = max(maxi, sum);
11
12            if (sum < 0)
13                sum = 0;
14        }
15
16        return maxi;
17    }
18};