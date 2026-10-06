1class Solution {
2public:
3    vector<vector<int>> levelOrder(TreeNode* root) {
4        vector<vector<int>> ans;
5
6        if (root == NULL)
7            return ans;
8
9        queue<TreeNode*> q;
10        q.push(root);
11
12        while (!q.empty()) {
13            int n = q.size();
14            vector<int> level;
15
16            for (int i = 0; i < n; i++) {
17                TreeNode* node = q.front();
18                q.pop();
19
20                level.push_back(node->val);
21
22                if (node->left != NULL)
23                    q.push(node->left);
24
25                if (node->right != NULL)
26                    q.push(node->right);
27            }
28
29            ans.push_back(level);
30        }
31
32        return ans;
33    }
34};