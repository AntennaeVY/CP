#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int ans = 1, cnt = 1;
	
	for(int i=1; i < n; i++) {
		if (a[i] >= a[i-1]) 
			cnt++;
		else
			ans = max(ans, cnt), cnt = 1;
	}
	
	cout << max(ans, cnt) << endl;
}