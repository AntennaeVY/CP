#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		if (n % 2) {
			cout << -1 << endl;
			continue;
		}
		
		bool ok = true;
		map<char, int> cnt;
		
		for(int i=0; i < n; i++) {
			cnt[s[i]]++;
			
			if (cnt[s[i]] > n/2)
				ok = false;
		}
		
		if (!ok) {
			cout << -1 << endl;
			continue;
 		}
 		
 		
 		int ans = 0;
 		map<char, int> dup;
 		
 		for(int i=0; i < n; i++) {
 			if (s[i] == s[n-1-i])
 			 	dup[s[i]]++;
 		}
 		
 		priority_queue<int> pq;
 		
 		for(auto x : dup) {
 			pq.push(x.second / 2);
 		}
 		
 		while(pq.size() > 1) {
 			int x1 = pq.top();
 			pq.pop();
 			
 			int x2 = pq.top();
 			pq.pop();
 			
			x1--, x2--;
			
			if (x1)
				pq.push(x1);
			
			if (x2)
				pq.push(x2);
 				
 			ans += 1;
 		}
 		
 		if (!pq.empty()) {
 			ans += pq.top();
 		}
 		
 		cout << ans << endl;
	}
}