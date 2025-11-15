#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<string> v(2);
	for(auto &vi : v) cin >> vi;
	
	string ans = "";
	
	int cnt = 0;
	for(int i=0; i < n; i++) {
		if (cnt && v[0][i] == '.' && cnt % 2 == 0) {
			ans += (cnt == 2 ? 'v' : 'w');
			cnt = 0;
		} else if (v[0][i] != '.') {
			cnt++;
		}
	}
	
	ans += (cnt == 2 ? 'v' : 'w');
	
	cout << ans << "\n";
}