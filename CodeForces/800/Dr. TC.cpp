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
		
		
		int ones = count(s.begin(), s.end(), '1');
		int cnt = 0;
		
		for(int i=0; i < n; i++) {
			int d = 0;
			
			if (s[i] == '0')
				d = 1;
			else
				d = -1;
			
			cnt += ones + d;
		}
		
		cout << cnt << endl;
	}
}