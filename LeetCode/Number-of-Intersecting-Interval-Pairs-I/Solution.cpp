1class Solution {
2public:
3    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
4        int n = intervals.size();
5        long long ans = 0;
6
7        sort(intervals.begin(), intervals.end());
8
9        multiset<int> ends;
10
11        for (auto &interval : intervals) {
12            int start = interval[0];
13
14            auto it = ends.lower_bound(start);
15            ans += distance(it, ends.end());
16
17            ends.insert(interval[1]);
18        }
19
20        return ans;
21    }
22};
23