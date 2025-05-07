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
		
		vector<int> odd, even;
		for(int i=0; i < n; i++) {
			if (a[i] % 2)
				odd.push_back(a[i]);
			else
				even.push_back(a[i]);
		}
		
		if (!even.size() || !odd.size()) {
			cout << *max_element(a.begin(), a.end()) << endl;
			continue;
		}
		
		long long sum = accumulate(a.begin(), a.end(), 0LL);
	
		cout << sum - (odd.size() - 1) << endl;
	}
}