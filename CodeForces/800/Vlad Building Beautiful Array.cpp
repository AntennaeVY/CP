#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> odd, even;
		for(int i=0; i < n; i++) {
			if (a[i] % 2)
				odd.push_back(a[i]);
			else
				even.push_back(a[i]);
		}
		
		if (odd.empty() || even.empty()) {
			cout << "YES" << endl;
			continue;
		}
		
		if (*min_element(odd.begin(), odd.end()) < *min_element(even.begin(), even.end())) {
			cout << "YES" << endl;
			continue;
		}
		
		cout << "NO" << endl;
	}
}