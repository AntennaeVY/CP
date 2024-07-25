#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    vector<int> a(n);
	    for(auto &ai : a) cin >> ai;
	    
	    map<int, int> m;
	    for(auto &ai : a) m[ai]++;
	    
	    vector<int> b;
	    for(auto [ai, c] : m) b.push_back(c);
	    
	    sort(b.rbegin(), b.rend());
	    
	    int ans = 0, sum = 0;
	    
	    for(int i=0; i < b.size(); i++) {
	        sum += b[i];
	        
	        ans = max(ans, (i+1) * (sum / (i+1)));
	    }
	    
	    cout << ans << endl;
	}

}
