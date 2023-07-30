#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  
  while(t--) {
    int n, x;
    cin >> n >> x;
  
  	vector<int> a(n);
  	for(auto &ai:a) cin >> ai;
  	
  	vector<int> f(n+1, INT_MIN);

	for(int l=0; l < n; l++) {
		int sum = 0;
		
		for(int r=l; r < n; r++) {
			sum += a[r];
			f[r-l+1] = max(f[r-l+1], sum);
		}
	}
	
	for(int k=0; k <= n; k++) {
		int ans = 0;
	
		for(int i=0; i <= n; i++) {
			ans = max(ans, f[i] + x * min(i, k));
		}
		
		cout << ans << " ";
	}
	
	cout << endl;
  }
}