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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool can = true;
        int r = 1;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* ptr = q.front();
                q.pop();

                if (ptr->left)
                    q.push(ptr->left);

                if (ptr->right)
                    q.push(ptr->right);

                level.push_back(ptr->val);
            }

            for(int i=0; i < size; i++) {
                if (level[i] % 2 != r)
                    can = false;

                if (i+1 == size)
                    continue;

                if (r && level[i] >= level[i+1])
                    can = false;
                else if (!r && level[i] <= level[i+1])
                    can = false;
            }

            r = 1-r;
        }

        return can;
    }
};