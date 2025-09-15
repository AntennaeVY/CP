#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> a(5, -1), ans(6, 0);

	for(int i=0; i < n; i++) {
		int cnt = 0;
		
		vector<int> b(5);
		for(auto &bi : b) cin >> bi;
		
		for(int j=0; j < 5; j++) {
			if (b[j] > a[j]) {
				a[j] = max(b[j], a[j]);
				cnt++;
			} 
		}
		
		ans[cnt]++;
	}
	
	for(int i=3; i <= 5; i++) {
		cout << ans[i] << " \n"[i==5];
	}
}