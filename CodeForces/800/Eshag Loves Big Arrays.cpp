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
		
		cout << n - count(a.begin(), a.end(), *min_element(a.begin(), a.end())) << endl;
	}
}