#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int ans = 0;
	set<long long> s = {0};
	vector<long long> a(n), ps(n+1, 0);
	
	for(int i=0; i < n; i++) {
		cin >> a[i];
		ps[i+1] = ps[i] + a[i];
		
		if (s.count(ps[i+1])) {
			ans++;
			s.clear();
			s.insert(0);
			ps[i+1] = a[i];
		}
			
		s.insert(ps[i+1]);
	}
	
	cout << ans << endl;
}