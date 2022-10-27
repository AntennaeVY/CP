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
    void bfs(TreeNode* root, vector<vector<int>> &ans) {
        if (!root) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> siblings;
            TreeNode* node = q.front();
            q.pop();
            
            int size = q.size();
            siblings.push_back(node->val);
            
            if (node->left){
                q.push(node->left);
            }
        
            if (node->right){
                q.push(node-> right);
            }
            
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                siblings.push_back(curr->val);
                
                if (curr->left){
                    q.push(curr->left);
                }
        
                if (curr->right){
                    q.push(curr->right);
                }   
            }
            
            if (!siblings.empty())
                ans.push_back(siblings);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(root, ans);
        
        return ans;
    }
};