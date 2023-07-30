/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> dfs(Node* root) {
        vector<int> traversal;
        vector<Node*> stack = {root};
        
        if (!root) return traversal;
        
        while(!stack.empty()) {
            Node* curr = stack.back();
            stack.pop_back();
            
            traversal.push_back(curr->val);
            
            for(auto node = curr->children.rbegin(); node != curr->children.rend(); node++) {
                stack.push_back(*node);
            }
        }
        
        return traversal;
    } 
    
    vector<int> preorder(Node* root) {
        return dfs(root);
    }
};