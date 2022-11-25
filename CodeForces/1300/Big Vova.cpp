#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		unordered_map<int,int> m;
		int mx = 0;
		
		vector<int> a(n);
		for(auto &ai:a) {
			cin >> ai;
			
			mx = max(ai, mx);
			m[ai]++;
		}
		
		cout << mx << " ";
		m[mx]--;
		int gcd = mx;
		
		for(int i=1; i < n; i++) {	
			int newGcd = 0, num = 0;
					
			for(int j=0; j < n; j++) {
				if (__gcd(gcd, a[j]) > newGcd && m[a[j]]) {
					newGcd = __gcd(gcd, a[j]);
					num = a[j];
				}
			}
			
			gcd = newGcd;
			cout << num << " ";
			m[num]--;
		}
		
		cout << endl;
	}
}