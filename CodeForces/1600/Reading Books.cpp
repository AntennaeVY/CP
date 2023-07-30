#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> alice, bob, both;
	
	for(int i=0; i < n; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		
		if (a == 1 && b == 1)
			both.push_back(t);
		else if (a == 1)
			alice.push_back(t);
		else if (b == 1)
			bob.push_back(t);
	}
	
	if (alice.size() + both.size() < k || bob.size() + both.size() < k) {
		cout << -1 << endl;
		return 0;
	}
	
	sort(alice.begin(), alice.end());
	sort(bob.begin(), bob.end());
	sort(both.begin(), both.end());
	
	vector<long long> ps_alice(k+1, 0), ps_bob(k+1, 0), ps_both(k+1);
	for(int i=0; i < k; i++) {
		if (i < alice.size())
			ps_alice[i+1] = ps_alice[i] + alice[i];
		else
			ps_alice[i+1] = 1e18;
		
		if (i < bob.size())
			ps_bob[i+1] = ps_bob[i] + bob[i];
		else
			ps_bob[i+1] = 1e18;
		
		if (i < both.size())
			ps_both[i+1] = ps_both[i] + both[i]; 
		else
			ps_both[i+1] = 1e18;
	}
	
	long long ans = 1e18;
	int need = max(max(0, k-(int)alice.size()), max(0, k-(int)bob.size()));
	
	for(int i=need; i <= k; i++) {
		ans = min(ans, ps_both[i] + ps_alice[k-i] + ps_bob[k-i]);
	}
	
	cout << ans << endl;
}