#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		vector<int> cnt(2, 0);
		for(auto c : s) cnt[c - '0']++;
		
		int x = min({cnt[0], cnt[1], n/2 - k});
		
		cnt[0] = max(0, cnt[0] - x);
		cnt[1] = max(0, cnt[1] - x);
		
		if (cnt[0] / 2 + cnt[1] / 2 == k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}