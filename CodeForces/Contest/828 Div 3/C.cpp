#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		char c;
		string s;
		
		cin >> n >> c >> s;
		
		if (c == 'g') {
			cout << 0 << endl;
			continue;
		}
		
		vector<int> greenIndexes;
		
		for(int i=0; i < n; i++) {
			if (s[i] == 'g')
				greenIndexes.push_back(i);
		}
		
		greenIndexes.push_back(n + greenIndexes[0]);
		
		int j = 0;
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			if (s[i] == c) {
				while(greenIndexes[j] < i) j++;
				
				ans = max(ans, greenIndexes[j]-i);
			}
		}
		
		cout << ans << endl;
	} 
}