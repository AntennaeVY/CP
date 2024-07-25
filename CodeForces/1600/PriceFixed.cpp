#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<long long> a(n), b(n);
	for(int i=0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	
	long long cnt = 0, ans = 0;
	
	vector<int> z(n);
	iota(z.begin(), z.end(), 0);
	
	sort(z.begin(), z.end(), [&](int i, int j){
		if (b[i] == b[j])
			return a[i] < a[j];
		
		return b[i] < b[j];
	});
	
	int l=0, r=n-1;
	
	while(l <= r) {
		if (b[z[l]] <= cnt) 
			cnt += a[z[l]], ans += a[z[l]], l++;
		else {
			long long x = min(a[z[r]], b[z[l]] - cnt);
			
			a[z[r]] -= x, cnt += x, ans += 2*x;
			
			if (a[z[r]] == 0)
				r--;
		}
	}
	
	cout << ans << endl;
}