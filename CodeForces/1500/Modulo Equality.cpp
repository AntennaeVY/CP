#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n), b(n);

	for(int i=0; i < n; i++) {
		cin >> a[i];
	}
	
	for(int i=0; i < n; i++) {
		cin >> b[i];
	}
	
	sort(b.begin(), b.end());
	
	auto check = [&](vector<int> &x, int &add) -> bool {
		sort(x.begin(), x.end(), [&](auto i, auto j){ 
			return (i+add) % m < (j+add) % m;
		});
		
		for(int i=0; i < n; i++) {
			if ((x[i] + add) % m != b[i])
				return false;
		}
		
		return true;
	};


	set<int> pos;

	for(int i=0; i < n; i++) {
		pos.insert((b[0] - a[i] + m) % m);
	}
	
	for(auto &x : pos) {
		int val = x;
		
		if (check(a, val)) {
			cout << val << endl;
			return 0;
		}
	}
}