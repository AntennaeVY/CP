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
		
		int mn = *min_element(a.begin(), a.end());
		int mx = *max_element(a.begin(), a.end());
		
		cout << 1LL*(mx - mn)*(n-1) << endl;
		}
}