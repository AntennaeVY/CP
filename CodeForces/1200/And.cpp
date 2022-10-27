#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	
	vector<int> a(n);
	unordered_map<int,int> present, seen;
	
	int ans = -1;
	bool already = false;

	for(int i=0; i < n; i++) {
		cin >> a[i];
		
		present[a[i]]++;
		
		if (present[a[i]] > 1) 
			already = true;
	}
	
	if (already) {
		cout << 0 << endl;
		return 0;
	}
	
	for(int i=0; i < n; i++) {
		int operation = a[i]&x;
		
		if (operation != a[i] && present[operation]) {
			ans = 1;
			break;
		}
		
		if (seen[operation]) {
			ans = 2;
		}
		
		seen[operation]++;
	}
	
	cout << ans << endl;
}