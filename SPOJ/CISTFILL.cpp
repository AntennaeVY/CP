#include<bits/stdc++.h>
using namespace std;

const long double EPS = 1e-7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> b(n), h(n), w(n), d(n);
		for(int i=0; i < n; i++) {
			cin >> b[i] >> h[i] >> w[i] >> d[i];
		}
		
		int v;
		cin >> v;
		
		long long total = 0;
		for(int i=0; i < n; i++) {
			total += h[i] * w[i] * d[i];
		}
		
		if (v > total) {
			cout << "OVERFLOW" << endl;
			continue;
		}
		
		long double l=0, r=1e7;
		while(r-l > EPS) {
			long double x = l + (r-l)/2;
			
			long double sum = 0;
			
			for(int i=0; i < n; i++) {
				if (b[i] - x > EPS)
					continue;
					
				int end = b[i] + h[i];
				
				if (end - x > EPS)
					sum += (x - b[i]) * w[i] * d[i];
				else 
					sum += h[i] * w[i] * d[i];
			}
			
			
			if (sum - v >= -EPS)
				r = x;
			else
				l = x;
		}
		
		
		cout << fixed << setprecision(2) << r << "\n";
	}
}