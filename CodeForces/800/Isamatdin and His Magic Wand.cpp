#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int odd = 0;
		
		for(int i=0; i < n; i++) {
			odd += a[i] % 2;
		}
		
		if (odd == n || odd == 0) {
		} else {
			sort(a.begin(), a.end());
		}
		
		for(auto &ai : a)
			cout << ai << " ";
		cout << "\n";
	}
}