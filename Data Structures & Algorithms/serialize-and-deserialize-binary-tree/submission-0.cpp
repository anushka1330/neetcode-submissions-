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

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "N,";
        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* build(stringstream& ss) {
        string s;
        getline(ss, s, ',');

        if (s == "N") return NULL;

        TreeNode* root = new TreeNode(stoi(s));
        root->left = build(ss);
        root->right = build(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};
