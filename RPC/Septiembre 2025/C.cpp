#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int c;
	cin >> c;
	
	vector<int> d(c);
	for(auto &di : d) cin >> di;
	
	
	int n = accumulate(d.begin(), d.end(), 0LL) / 3;
	sort(d.begin(), d.end());
	
	vector<int> t(3);
	t[0] = n;
	
	for(int i=0; i < c; i++) {
		int p1 = t[1], p2 = t[2];
		
		if (t[0]) {
			int x = min(t[0], d[i]);
		
			t[0] -= x, d[i] -= x;
			t[1] += x;
		}
		
		if (p1) {
			int x = min(p1, d[i]);

			t[1] -= x, d[i] -= x;
			t[2] += x;
		}
		
		
		if (p2) {
			int x = min(p2, d[i]);
			
			t[2] -= x, d[i] -= x;
		}
	}
	

	
	if (t[0] == 0 && t[1] == 0 && t[2] == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
}