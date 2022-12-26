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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        
        return getMatchingSum(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int getMatchingSum(TreeNode* root, int targetSum, long long cnt=0) {
        if (!root)
            return 0;
        
        long long current = cnt + root->val;

        int ans = (current == targetSum);
        ans += getMatchingSum(root->left, targetSum, current);
        ans += getMatchingSum(root->right, targetSum, current);

        return ans;
    }
};