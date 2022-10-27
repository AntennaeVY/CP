class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        map<char, int> m;
        
        int ans = 0;
        int mx = 0;
        
        for(int r=0; r < s.size(); r++) {
            char key = s[l];
            m[s[r]]++;
            
            mx = max(m[s[r]], mx);
            
            while(r-l+1 - mx > k) {
                m[s[l]]--;
                
                if (m[s[l]] == 0)
                    m.erase(s[l]);
                
                l++;
            }
            
            ans = max(ans, r-l+1);
        }
        
        return ans;
    }
};