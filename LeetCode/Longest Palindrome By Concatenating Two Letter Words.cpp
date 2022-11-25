class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int palindrome_length = 0;
        bool can_append_palindrome = false;
        map<string, int> count;

        for(auto word : words) {
            count[word] += 1;
        }

        for(int i=0; i < words.size(); i++) {
            string reversed_word = words[i];
            reverse(reversed_word.begin(), reversed_word.end());
            
            if (count[reversed_word] == 0 || count[words[i]] == 0) continue;

            if (words[i] == reversed_word && count[words[i]] == 1) {
                can_append_palindrome = true;
                continue;
            }
            
            count[words[i]] -= 1;
            count[reversed_word] -= 1;

            palindrome_length += 4;
        }

        if (can_append_palindrome) {
            palindrome_length += 2;
        }

        return palindrome_length;
    }
};