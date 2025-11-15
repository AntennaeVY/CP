#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		long long s = accumulate(a.begin(), a.end(), 0LL);
		
		if (s % 3) {
			cout << "0 0\n";
		} else {
			cout << "1 2\n";
		}
	}
}