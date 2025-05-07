#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		string r = s;
		reverse(r.begin(), r.end());
		
		int mn = *min_element(s.begin(), s.end());
		int mx = *max_element(s.begin(), s.end());
		
		if (mn == mx) {
			cout << "NO" << endl;
			continue;
		} 
		
		if (s >= r && k == 0) {
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
	}
}