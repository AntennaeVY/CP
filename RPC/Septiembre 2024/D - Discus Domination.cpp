#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int l = 0, ans = 0;
	multiset<int> s;
	
	for(int r=0; r < n; r++) {
		s.insert(a[r]);
		
		while(r-l+1 > m+1) {
			s.erase(s.find(a[l]));
			l++;
		}
		
		ans = max(ans, a[r] - *s.begin());
	}
	
	ans = max(ans, a.back() - *s.begin());
	
	cout << ans << endl;
}