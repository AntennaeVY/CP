#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  while (true) {
    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0)
    	break; 
    
    vector<vector<int>> h(n, vector<int>(m));
    
    for(int i=0; i < n; i++) {
    	for(int j=0; j < m; j++) {
    		cin >> h[i][j];
    	}
    }
    
    int q;
    cin >> q;
    
    while(q--) {
    	int x, y;
    	cin >> x >> y;
    	
    	int ans = 0;
    	
    	for(int i=0; i < n; i++) {
    		
    		int l=-1, r = m;
    		while(l + 1 < r) {
    			int mid = l + (r-l)/2;
    			
    			if (h[i][mid] >= x)
    				r = mid;
    			else
    				l = mid;
    		}
    		
    		if (r == m || h[i][r] > y)
    			continue;
    		
    		int start = r;
    		
    		l=start, r = m;
    		while(l + 1 < r) {
    			int mid = l + (r-l)/2;
    			
    			int dist = mid - start;
    			
    			if (i + dist >= n) {
    				r = mid;
    				continue;
    			}
    			
    			if (h[i + dist][mid] <= y)
    				l = mid;
    			else
    				r = mid;
    		}
    		
    		ans = max(ans, l - start + 1);
    	}
    	
    	cout << ans << endl;
    }
    
    	cout << "-" << endl;
  }
}