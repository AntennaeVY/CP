#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, q;
		cin >> n >> q;
		
		vector<ll> h(n), w(n);
		vector<vector<ll>> ps(1001, vector<ll>(1001, 0));
		
		for(int i=0; i < n; i++) {
			cin >> h[i] >> w[i];
			
			ps[h[i]][w[i]] += h[i] * w[i];
		}
		
		for(int i=1; i <= 1000; i++) {
			for(int j=1; j <= 1000; j++) {
				ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1]; 
			}
 		}
		
		while(q--) {
			int hs, ws, hb, wb;
			cin >> hs >> ws >> hb >> wb;
			
			cout << ps[hb-1][wb-1] - ps[hb-1][ws] - ps[hs][wb-1] + ps[hs][ws] << endl;
		}
	}
}