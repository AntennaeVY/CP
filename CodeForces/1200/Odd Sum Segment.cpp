#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int q;
	cin >> q;
	
	while(q--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
	
		int odd = 0;
	
		for(int i=0; i < n; i++) {
			odd += a[i] % 2;
		}
		
		if (odd < k || (odd - k) % 2 == 1) {
			cout << "NO" << endl;
			continue;
		} else
			cout << "YES" << endl;
			
		k--;
	
		for(int i=0; i < n; i++) {
			if (a[i] % 2 && k) {
				cout << i+1 << " ";
				k--;
			}
		}
		
		cout << n << endl;
	}
}