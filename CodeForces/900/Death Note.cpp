#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int r = 0;
	
	for(int i=0; i < n; i++) {
		int cnt = 0;
		
		if (a[i] < m - r) {
			r += a[i];
			cout << 0 << " ";
			
			continue;
		}

		a[i] -= m - r, cnt += 1;	
		cnt += (a[i] + m - 1) / m - (a[i] % m != 0);
		r = a[i] % m; 
		
		cout << cnt << " ";
	}
}