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
    bool isSymmetric(TreeNode* root) {
        function<bool(TreeNode* p, TreeNode* q)> is_mirror;

        is_mirror = [&](TreeNode* p, TreeNode* q){
            if (p == NULL || q == NULL)
                return p == q;

            return (
                p->val == q->val &&
                is_mirror(p->left, q->right) && 
                is_mirror(p->right, q->left)
            );
        };

        if (!root)
            return true;

        return is_mirror(root->left, root->right);
    }
};