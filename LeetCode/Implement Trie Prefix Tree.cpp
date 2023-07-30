class TrieNode {
    public:
        map<char, TrieNode*> children = {};
        char value = '*';
        bool end_of_word = false;

        TrieNode(char c) {
            value = c;
        }

        TrieNode() {
            
        }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        
        for(char c : word) {
            TrieNode* character = new TrieNode(c);

            if (!node->children[c])
                node->children[c] = character;

            node = node->children[c];
        }

        node->end_of_word = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        
        for(char c : word) {
            if (!node->children[c])
                return false;
            
            node = node->children[c];
        }

        return node->end_of_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        
        for(char c : prefix) {
            if (!node->children[c])
                return false;
            
            node = node->children[c];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */