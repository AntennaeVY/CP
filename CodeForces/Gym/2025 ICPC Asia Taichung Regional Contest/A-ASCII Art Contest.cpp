#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> v(3);
	for(auto &vi : v) cin >> vi;
	
	sort(v.begin(), v.end());
	
	if (v[2] - v[0] >= 10) {
		cout << "check again\n";
	} else {
		cout << "final " << v[1] << "\n"; 
	}
}