#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int ans = 1e9; 
	map<int, array<int, 2>> m;
	
	sort(a.begin(), a.end());
	for(int i=0; i < n; i++) {
		for(int j=0; (a[i] >> j) >= 0; j++) {
			int num = (a[i] >> j);
			
			m[num][0] += 1;
			m[num][1] += j;
			
			if (m[num][0] >= k) 
				ans = min(ans, m[num][1]);
				
			if (num == 0)
				break;
		}
	} 
	
	cout << ans << endl;
}