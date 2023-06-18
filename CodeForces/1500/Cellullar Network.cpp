#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n), b(m);
	for(auto &ai : a)
		cin >> ai;
		
	for(auto &bi : b)
		cin >> bi;
		
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
		
	int l=-1, r=2e9;
	while(l + 1 < r) {
		int x = l + (r-l)/2;
		
		bool ok = true;
		int j=0;
		
		for(int i=0; i < n; i++) {
			while(j+1 < m && b[j+1] <= a[i]) 
				j++;
				
			ok &= (abs(a[i]-b[j]) <= x || (j+1 < m && abs(b[j+1]-a[i]) <= x));
		}
		
		if (ok)
			r = x;
		else
			l = x;
	}
	
	cout << r << endl;
}