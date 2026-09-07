class Solution {
public:

    bool check(int k, vector<int>& piles, int h) {
        long long hours = 0;

        for (int bananas : piles) {
            hours += (bananas + k - 1) / k;

            if (hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int l = 1;
        int r = 1e9;
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