#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int amt = 0;
	map<char, int> cnt;
	
	for(int i=0; i < n; i++) {
		cnt[s[i]]++;
		
		if (cnt[s[i]] == 1)
			amt++;
	}
	
	int l=0, ans = 1e9;
	map<char, int> window;
	
	for(int r=0; r < n; r++) {
		window[s[r]]++;
		
		while(window[s[l]] != 1) {
			window[s[l]]--, l++;
		}	
		
		if (window.size() == amt)
			ans = min(ans, r-l+1);
	}
	
	cout << ans << endl;
}