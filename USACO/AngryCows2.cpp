#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	// freopen("angry.in", "r", stdin);
	// freopen("angry.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<long long> p(n);
	for(int i=0; i < n; i++) {
		cin >> p[i];
		p[i] *= 10;
	}
	
	sort(p.begin(), p.end());
	
	vector<long long> needL(n), needR(n);
	
	needL[0] = 0;
	for(int i=1; i < n; i++) {
		needL[i] = max(needL[i-1], p[i] - p[i-1]);
	}
	
	needR[n-1] = 0;
	for(int i=n-2; i >= 0; i--) {
		needR[i] = max(needR[i+1], p[i+1] - p[i]);
	}
	
	auto left = [&](int i, long long x, long long r) -> bool {
		int j = lower_bound(p.begin(), p.begin() + i + 1, x-r) - p.begin();
		return needL[j] <= max(r-10, 0LL);
	};
	
	auto right = [&](long long i, long long x, long long r) -> bool { 
		int j = prev(upper_bound(p.begin() + i, p.end(), x+r)) - p.begin();

		return needR[j] <= max(r-10, 0LL); 
	};
 	
	long long l=-1, r=1e10+5;
	while(l + 1 < r) {
		long long x = l + (r-l)/2;
		
		bool ok = false;
		
		for(int i=0; i < n; i++) {
			bool can = true;
			
			can &= left(i, p[i] + x, x);
			can &= right(i, p[i] + x, x);
			
			if (can) {
				ok = true;
				break;
			}
		}
		
		if (ok)
			r = x;
		else
			l = x;
	}
	
	cout << fixed << setprecision(1) << ((long double)(r) / 10) << "\n";
}