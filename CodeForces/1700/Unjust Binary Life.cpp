#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		long long n;
		cin >> n;
		
		string a, b;
		cin >> a >> b;
		
		vector<int> c0x(n+1), c0y(n+1), c1x(n+1), c1y(n+1);
		vector<int> px(n), py(n);
		for(int i=1; i <= n; i++) {
			c0x[i] += (a[i-1] == '0') + c0x[i-1];
			c0y[i] += (b[i-1] == '0') + c0y[i-1];
			
			c1x[i] += (a[i-1] == '1') + c1x[i-1];
			c1y[i] += (b[i-1] == '1') + c1y[i-1];
			
			px[i-1] = c0x[i] - c1x[i];
			py[i-1] = c1y[i] - c0y[i];
		}
		
		long long ans = n*n*(n+1)/2;
		long long sum = 0;
		
		sort(px.begin(), px.end());
		sort(py.begin(), py.end());
		
		// for(int i=0; i < n; i++) {
			// cout << px[i] << " ";
		// }
		// cout << endl;
// 		
		// for(int i=0; i < n; i++) {
			// cout << py[i] << " ";
		// }
		// cout << endl;
		
		int l = 0;
		for(int i=0; i < n; i++) {
			while(l < n && py[l] < px[i])
				l++;
				
			// cout << px[i] << " " << l << endl;
				
			sum += 1LL * px[i] * l;
			sum -= 1LL * px[i] * (n-l);
		}
		
		l = 0;
		for(int i=0; i < n; i++) {
			while(l < n && px[l] <= py[i])
				l++;
				
			sum += 1LL * py[i] * l;
			sum -= 1LL * py[i] * (n-l);
		}
		
		ans -= sum/2;
		
		cout << ans << "\n";
	}
}