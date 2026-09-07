class Solution {
public:

    bool check(int k, vector<int>& piles, int h) {
        long long hours = 0;

        for (int value : piles) {
            hours += value / k;

            if (value % k != 0)
                hours++;

            if (hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int l = 1, r = 1e9;
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, piles, h)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};