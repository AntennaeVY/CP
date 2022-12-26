#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		int teams = 0;
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		sort(a.rbegin(), a.rend());
		
		int l=0;
		for(int r=0; r < a.size(); r++) {
			int cnt = (r-l+1)*a[r];
			
			if (cnt >= x) {
				teams++;
				l = r+1;
			}
		}		
		
		cout << teams << endl;
	}
}