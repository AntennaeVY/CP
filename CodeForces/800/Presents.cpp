#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n), ans(n);
	for(auto &ai:a) cin >> ai;
	
	for(int i=0; i < n; i++) {
		ans[a[i]-1] = i+1;
	}
	
	for(auto &ai : ans)
		cout << ai << " ";
}