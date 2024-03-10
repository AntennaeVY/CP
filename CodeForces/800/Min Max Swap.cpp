#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		for(int i=0; i < n; i++) {
			if (a[i] > b[i])
				swap(a[i], b[i]);
		}
		
		cout << *max_element(a.begin(), a.end()) * *max_element(b.begin(), b.end()) << endl;
	}
}