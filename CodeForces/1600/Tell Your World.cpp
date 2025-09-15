#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

long double slope(ld x1, ld y1, ld x2, ld y2) {
	return (y2 - y1) / (x2 - x1);
}
// y - y1 = m * (x - x1);
// y - y1 = (y2 - y1) / (x2 - x1) * (x - x1);
// (x2 - x1)(y - y1) = (y2 - y1) * (x - x1);
// yx2 - x2y1 -yx1 = xy2 - y2x1 - xy1
bool check(ll x1, ll y1, ll x2, ll y2, ll x, ll y) {
	return y*x2 - x2*y1 - y*x1 == x*y2 - y2*x1 - x*y1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> y(n);
	for(auto &yi : y) cin >> yi;
	
	bool ans = false;
	
	for(int i=0; i < 3; i++) {
		for(int j=0; j < 3; j++) {
			if (j == i)
				continue;
				
			vector<int> v;
			
			for(int k=0; k < n; k++) {
				if (!check(i, y[i], j, y[j], k, y[k]))
					v.push_back(k);
			}

			if (ans || v.size() == 1) {
				ans = true;
				break;
			}
			
			if (v.empty())
				continue;
						
			ld s1 = slope(i, y[i], j, y[j]);
			ld s2 = slope(v[0], y[v[0]], v[1], y[v[1]]);
			
			if (s1 != s2)
				continue;
				
			bool can = true;
				
			for(int k=0; k < v.size(); k++) {
				can &= check(v[0], y[v[0]], v[1], y[v[1]], v[k], y[v[k]]);
			}
				
			if (can)
				ans = true;
		}
	}
	
	cout << (ans ? "Yes" : "No") << "\n";
}