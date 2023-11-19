#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		map<char, int> cnt;
		
		for(auto c : s)
			cnt[c]++;
			
		int odd = 0;
			
		for(auto &[x, y] : cnt)
			odd += y & 1;
		
		if (odd > k+1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}