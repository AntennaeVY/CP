#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> x(n);
	for(auto &xi : x) cin >> xi;
	
	sort(x.begin(), x.end());
	
	auto check = [&](int r){
		auto start = x.begin();
		
		for(int i=0; i < k; i++) {
			if (start == x.end())
				return true;
			
			start = upper_bound(x.begin(), x.end(), *start + 2*r);
		}
		
		return start == x.end();
	};
	
	int l = -1,  r = 1e9 + 1;
	
	while(l + 1 < r) {
		int mid = l + (r-l)/2;
		
		if (check(mid)) 
			r = mid;
		else
			l = mid;
	}
	
	cout << r << endl;
}