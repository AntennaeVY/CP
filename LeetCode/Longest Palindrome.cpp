class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> freq;
        
        for (int i=0; i < s.size(); i++) {
            freq[s[i]]++;    
        }
        
        int ans = 0;
        bool odd = false;
        
        for(auto x : freq) {
            ans += x.second - x.second%2;
            odd |= x.second%2;
        }
        
        return ans+odd;
    }
};