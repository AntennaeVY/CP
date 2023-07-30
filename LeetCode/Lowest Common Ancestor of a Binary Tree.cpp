/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root, *small, *big;
        
        small = p;
        big = q;
        
        if (p->val > q->val)
            swap(small, big);
        
        while(true) {
            if (big->val >= ans->val && small->val <= ans->val)
                return ans;
            
            if (big->val > ans->val && small->val > ans->val)
                ans = ans->right;
            else
                ans = ans->left;
        }
    }
};