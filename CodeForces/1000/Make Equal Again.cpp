#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int left = 0;
		int right = 0;
		
		for(int i=0; i < n; i++) {
			if (a[i] == a[0])
				left++;
			else
				break;
		}
		
		for(int j=n-1; j >= 0; j--) {
			if (a[j] == a[n-1])
				right++;
			else
				break;
		}
		
		if (a[0] == a[n-1]) {
			cout << n - min(n, left + right) << "\n";
		} else {
			cout << n - max(left, right) << "\n";
		}
		
	}
}