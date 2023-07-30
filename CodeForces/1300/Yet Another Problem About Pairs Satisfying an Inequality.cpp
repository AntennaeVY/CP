#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), deleted(n+1, 0);
		vector<int> good;
		for(auto &ai:a) cin >> ai;
		
		for(int i=0; i < n; i++) {
			deleted[i+1] = deleted[i];
			
			if (a[i] < i+1)
				good.push_back(a[i]);
			else
				deleted[i+1]++;
		}
		
		long long ans = 0;
		
		for(int i=0; i < good.size(); i++) {
			ans += max(good[i] - 1, 0) - deleted[max(good[i] - 1, 0)];
		}
		
		cout << ans << endl;
	}
}