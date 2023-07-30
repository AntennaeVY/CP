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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        function<bool(TreeNode*, TreeNode*)> is_structural_equal;

        is_structural_equal = [&](TreeNode* p1, TreeNode* q1){
            if (p1 == NULL && q1 == NULL)
                return true;
            else if (p1 == NULL || q1 == NULL)
                return false;

            return (
                p1->val == q1->val &&
                is_structural_equal(p1->left, q1->left) && 
                is_structural_equal(p1->right, q1->right)
            );
        };

        return is_structural_equal(p, q);
    }
};