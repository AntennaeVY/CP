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
		
		int cnt = 0, ans = 0;
		
		for(int i=0; i < n; i++) {
			if (cnt > 0 && a[i] == 0)
				ans++;
				
			cnt += a[i];
		}
		
		for(int i=n-1; a[i] != 1; i--) {
			ans--;
		}
		
		cout << (cnt > 1 ? ans : 0) << endl;
	}
}