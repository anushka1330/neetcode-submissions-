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
    int idx = 0;
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& preorder, int l, int r) {
        if (l > r) return NULL;

        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);

        int pos = mp[val];

        root->left = solve(preorder, l, pos - 1);
        root->right = solve(preorder, pos + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return solve(preorder, 0, inorder.size() - 1);
    }
};