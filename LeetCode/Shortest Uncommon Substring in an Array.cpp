class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        map<string, int> cnt;
        vector<map<string, int>> v(n);
        
        vector<string> ans(n);
        
        for(int i=0; i < n; i++) {
            int m = arr[i].size();
            
            cnt[arr[i]]++, v[i][arr[i]]++;
            
            for(int j=1; j < m; j++) {
                for(int k=0; k+j <= m; k++) {
                    string substr = arr[i].substr(k, j);
                    
                    cnt[substr]++, v[i][substr]++;
                }
            }
        }
        
        for(int i=0; i < n; i++) {
            int m = arr[i].size();
            
            ans[i] = arr[i];
            
            bool can = false;
            
            for(int j=1; j <= m; j++) {
                if (can)
                    break;
                
                for(int k=0; k+j <= m; k++) {
                    string substr = arr[i].substr(k, j);
                    
                    if (cnt[substr] - v[i][substr] > 0)
                        continue;
                    
                    if (substr.size() < ans[i].size())
                        ans[i] = substr;
                    
                    ans[i] = substr < ans[i] ? substr : ans[i];
                    can = true;
                }
            }
            
            if (!can)
                ans[i] = "";
        }
        
        return ans;
    }
};