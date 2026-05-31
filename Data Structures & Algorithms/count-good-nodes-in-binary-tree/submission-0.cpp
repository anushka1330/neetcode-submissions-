/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* root, int mx) {
        if (!root) return 0;

        int ans = (root->val >= mx);

        mx = max(mx, root->val);

        ans += dfs(root->left, mx);
        ans += dfs(root->right, mx);

        return ans;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};