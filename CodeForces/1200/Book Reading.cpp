#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int q;
	cin >> q;
	
	while(q--) {
		long long n, m;
		cin >> n >> m;
		
		if (m > n) {
			cout << 0 << endl;
			continue;
		} else if (m == n) {
			cout << m%10 << endl;
			continue;
		}
	
		vector<long long> digs = { m%10 };
		long long num = 2*m;
		
		while(num % 10 != digs[0]) {
			digs.push_back(num % 10);
			num += m;
		}	
		
		long long last = n - n % m;
		int idx = 0;
		
		for(int i=0; i < digs.size(); i++) {
			if (digs[i] == last % 10) {
				idx = i;
				break;
			}
		}
		
		long long ans = ((n/m)/digs.size()) * accumulate(digs.begin(), digs.end(), 0LL);

		if ((n/m) % digs.size() != 0)
			for(int i=0; i <= idx; i++) {
				ans += digs[i];
			}
		
		cout << ans << endl;
	}
}