class Solution {
public:
    static const int MOD = 1000000007;

    struct Node {
        long long val;
        int cnt;
    };

    vector<Node> seg;
    vector<long long> pw;
    vector<int> pref;

    Node merge(Node a, Node b) {
        return {
            (a.val * pw[b.cnt] + b.val) % MOD,
            a.cnt + b.cnt
        };
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            if (s[l] == '0')
                seg[idx] = {0, 0};
            else
                seg[idx] = {s[l] - '0', 1};
            return;
        }

        int mid = (l + r) / 2;
        build(idx * 2, l, mid, s);
        build(idx * 2 + 1, mid + 1, r, s);
        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql == l && qr == r)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(idx * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(idx * 2 + 1, mid + 1, r, ql, qr);

        return merge(
            query(idx * 2, l, mid, ql, mid),
            query(idx * 2 + 1, mid + 1, r, mid + 1, qr)
        );
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        pw.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;

        pref.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (s[i] == '0' ? 0 : s[i] - '0');

        seg.assign(4 * n + 5, {0, 0});
        build(1, 0, n - 1, s);

        vector<int> ans;
        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            long long sum = pref[q[1] + 1] - pref[q[0]];
            ans.push_back((cur.val * sum) % MOD);
        }

        return ans;
    }
};