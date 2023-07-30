#include<bits/stdc++.h>
using namespace std;

int ask(int i, int j) {
	cout << "? " << i << " " << j << endl;
	
	int x;
	cin >> x;
	
	return x;
}

int main() {
	int n;
	cin >> n;
	
	int mx = 1;
	vector<int> ans(n+1);
	
	for(int i=2; i <= n; i++) {
		int x = ask(i, mx);
		int y = ask(mx, i);
		
		if (y > x) {
			ans[mx] = y;
			mx = i;
		} else {
			ans[i] = x;
		}
	}
	
	ans[mx] = n;
	
	cout << "! ";

	for(int i=1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	
	cout << endl;
}