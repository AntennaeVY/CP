#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	sort(a.rbegin(), a.rend());
	
	function<int(int)> check;
	check = [&](int x) {
		long long sum = 0;
		
		for(int i=0; i < n; i++) {
			sum += max(0, a[i] - i/x);
		}
		
		return sum >= m;
	};
	
	int l=0, r = n+1;
	while(l + 1 < r) {
		int x = l + (r-l)/2;
		
		if (check(x))
			r = x;
		else
			l = x;
	}
	
	if (r == n+1)
		cout << -1 << endl;
	else
		cout << r << endl;
}