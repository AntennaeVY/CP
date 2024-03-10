#include<bits/stdc++.h>
using namespace std;

// Overkill (?)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int, int> m;
		ordered_set s;
		vector<int> b(n);

		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			s.insert(x);
			cin >> b[i];
			
			m[b[i]] = x;
		}
		
		sort(b.begin(), b.end());
		
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			ans += s.order_of_key(m[b[i]]);
			
			s.erase(s.find(m[b[i]]));
		}
		
		cout << ans << endl;
	}
}