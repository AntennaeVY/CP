#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<tuple<int, int, int>, int> m;
		
		long long ans = 0;
		
		for(int i=0; i < n-2; i++) {
			tuple<int,int,int> t1,t2,t3,t4;
			
			t1 = {0, a[i+1], a[i+2]};
			t2 = {a[i], 0, a[i+2]};
			t3 = {a[i], a[i+1], 0};
			t4 = {a[i], a[i+1], a[i+2]};
			
			ans += m[t1] + m[t2] + m[t3] - 3*m[t4];
			
			
			m[t1]++, m[t2]++, m[t3]++, m[t4]++;
		} 
		
		cout << ans << endl;
	}
}