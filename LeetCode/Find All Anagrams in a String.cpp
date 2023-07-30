class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        
        vector<int> sm(26, 0), pm(26, 0);
        vector<int> ans;
        
        for(int i=0; i < p.size(); i++) {
            pm[p[i] - 'a']++;
        }
        
        int l=0;
        
        for(int r=0; r < s.size(); r++) {
            sm[s[r] - 'a']++;
            
            while(r-l+1 > p.size()) {
                sm[s[l++] - 'a']--;
            }
            
            bool ok = true;
            
            for(int i=0; i < 26; i++) {
                ok &= (sm[i] == pm[i]);
            }
            
            if (ok) {
                ans.push_back(l);
            }
        }
        
        return ans;
    }
};