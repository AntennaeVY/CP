#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	bool can = false;
	
	for(int i=1; i < n-1; i++) {
		can |= (a[i] == a[i-1] && a[i] == a[i+1]);
	}
	
	cout << (can ? "Yes" : "No") << endl;
}