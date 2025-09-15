#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		map<char,int> cnt;
		
		for(int i=0; i < n; i++) {
			cnt[s[i]]++;
		}
		
		bool can = false;
		
		for(int i=1; i < n-1; i++) {
			cnt[s[i]]--;
			
			if (cnt[s[i]])
				can |= true;
			
			cnt[s[i]]++;
		}
		
		cout << (can ? "YES" : "NO") << "\n";
	}
}