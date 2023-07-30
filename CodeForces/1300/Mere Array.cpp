#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		vector<int> sorted(a);
		sort(sorted.begin(), sorted.end());
		
		int min_element = sorted[0];
		bool ok = true;
		
		for(int i=0; i < n; i++) {
			if (a[i]%min_element != 0 && a[i] != sorted[i])
				ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}