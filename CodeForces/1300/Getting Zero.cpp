#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n), ans(n, 15);
	for(auto &ai:a) cin >> ai;
	
	for(int i=0; i < n; i++) {
		for(int j = 0; j <= 15; j++) {
			for(int k=0; k <= 15; k++) {
				if (((a[i]+j)*(1 << k))%32768 == 0) {
					ans[i] = min(ans[i], j+k);
				}
			}
		}
	}
	
	for(auto x : ans) {
		cout << x << " ";
	}
	
	cout << endl;
}