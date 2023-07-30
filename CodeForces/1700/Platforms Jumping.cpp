#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	
	vector<int> c(m);
	for(auto &ci : c) cin >> ci;
	
	int sum = accumulate(c.begin(), c.end(), 0);
	int dest = n+1 - sum;
	
	vector<int> ans(n, 0);
	
	bool ok = true;
	int pos = 0, curr = 0;
	
	while(curr <= m) {
		if (pos + d < dest && curr == m) {
			ok = false;
			break;
		}
		
		if (pos + d < dest) {
			for(int i=0; i < c[curr]; i++) {
				ans[pos+d-1+i] = curr+1;
			}
			
			pos += d + c[curr] - 1;
			dest += c[curr];
		} else {
			break;
		}
		
		curr++;
	}
	
	int last = n-1;
	
	for(int i=m-1; i >= curr; i--) {
		for(int j=0; j < c[i]; j++) {
			ans[last--] = i+1;
		}
	}
	
	cout << (ok ? "YES" : "NO") << endl;
	
	if (!ok)
		return 0;
	
	for(auto &ansi : ans) {
		cout << ansi << " ";
	}
	
	cout << endl;
}