/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  bool check(TreeNode* node, int* small, int* big) {
    if (!node) return true;

    if (small != NULL && node->val <= *small) return false;
    if (big != NULL && node->val >= *big) return false;

    return check(node->left, small, &node->val) &&
           check(node->right, &node->val, big);
  }

  bool isValidBST(TreeNode* root) { return check(root, NULL, NULL); }
};