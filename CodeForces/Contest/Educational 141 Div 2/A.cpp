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
		
		if (count(a.begin(), a.end(), a[0]) == n) {
			cout << "NO" << endl;
			continue;
		}
		
		sort(a.rbegin(), a.rend());
		
		if (a[0] == a[1]) {
			swap(a[1], a.back());
		}
		
		cout << "YES" << endl;
		for(auto ai : a)
			cout << ai << " ";
			
		cout << endl;
	}
}