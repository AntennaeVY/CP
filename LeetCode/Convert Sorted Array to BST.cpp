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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums, 0, nums.size()-1);
    }

    TreeNode* makeBST(vector<int>& nums, int l, int r) {
        TreeNode* root = new TreeNode();
        if (l > r)
            return NULL;

        int mid = l + (r-l)/2;

        root->val = nums[mid];
        root->left = makeBST(nums, l, mid-1);
        root->right = makeBST(nums, mid+1, r);

        return root;
    }
};