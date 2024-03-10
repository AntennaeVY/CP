#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    string s;
	    cin >> s;
	    
	    int n = s.size();
	    map<char, int> m;
	    
	    for(auto ch : s)
	        m[ch]++;
	        
	   int ans = 1e9;
	        
	    for(auto [ch, cnt] : m) {
	        int l = 0, c = 0;
	        
	        for(int r=0; r < n; r++) {
	            if (s[r] == ch)
	                c++;
	                
	            while(r-l+1 > cnt) {
	                if (s[l] == ch)
	                    c--;
	                    
	                l++;
	            }
	            
	            if (r-l+1 == cnt)
	                ans = min(ans, r-l+1 - c);
	        }
	    }
	    
	    cout << ans << endl;
	}

}
