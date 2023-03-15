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
		
		int ans = *max_element(a.begin(), a.end());
		int cnt = count(a.begin(), a.end(), ans);
		
		if(cnt == n) {
			cout << -1 << endl;
		} else {
			for(int i=0; i < n; i++) {
				if (a[i] != ans)
					continue;
					
				if (i > 0 && a[i-1] < ans || i < n-1 && a[i+1] < ans) {
					cout << i + 1 << endl;
					break;
				}  
			}
		}
	}
}