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
private:
    vector<int> in_order_traversal(TreeNode* root, vector<int> &v) {
        if (!root)
            return v;

        v = in_order_traversal(root->left, v);
        v.push_back(root->val);
        v = in_order_traversal(root->right, v);

        return v;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        // just in order traversal and chose index k;
        vector<int> v;
        v = in_order_traversal(root, v);

        return v[k-1];
    }
};