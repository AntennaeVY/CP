#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		vector<int> d(n), h(n);
		for(int i=0; i < n; i++)
			cin >> d[i] >> h[i];
			
		vector<int> a(n);
		for(int i=0; i < n; i++)
			a[i] = h[i] - d[i];
			
		int mn = *min_element(a.begin(), a.end());
		int mx = *max_element(d.begin(), d.end());
		
		if (mx >= x) {
			cout << 1 << endl;
			continue;
		}
		
		if (mn >= 0)
			cout << -1;
		else
			cout << (x - mx + abs(mn) - 1) / abs(mn) + 1;
			
		cout << endl;
	}
}