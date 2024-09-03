#include<bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	vector<int> d(n+1, INF);
	d[0] = -INF;
	
	for(int i=0; i < n; i++) {
		int l=0, r=n+1;
		while(l + 1 < r) {
			int m = l + (r-l)/2;
			
			if (d[m] < a[i])
				l = m;
			else
				r = m;
		}
		
		d[l+1] = min(d[l+1], a[i]);
	}
	
	int j=n;
	while(d[j] == INF) j--;
	
	cout << j << endl; 
}