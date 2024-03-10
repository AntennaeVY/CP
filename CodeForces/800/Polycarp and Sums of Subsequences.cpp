#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		vector<int> a(7);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		cout << a[0] << " " << a[1] << " " << a[6] - a[0] - a[1] << endl;
	}
}