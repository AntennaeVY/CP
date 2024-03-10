class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0, n = s.size();
        
        // Count odd length
        for(int i=0; i < n; i++) {
            int l=i, r=i;

            while(l >= 0 && r < n && s[l] == s[r])
                cnt++, l--, r++;
        }

        // Count even length
        for(int i=1; i < n; i++) {
            int l=i-1, r=i;

            while(l >= 0 && r < n && s[l] == s[r])
                cnt++, l--, r++;
        }

        return cnt;
    }
};