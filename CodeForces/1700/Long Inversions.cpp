#include<bits/stdc++.h>
using namespace std;

bool can(string &s, int x) {
	int n = s.size();
	vector<int> a(n+1, 0);
	
	int ops = 0, cnt = 0;
	
	for(int i=0; i < n; i++) {
		ops -= a[i];
		
		if (
			s[i] == '1' && ops % 2 == 0 || 
		    s[i] == '0' && ops % 2 == 1
		) {
			cnt += 1;
			continue;
		}
		
		if (i > n - x)
			continue;
			
		ops += 1, a[i+x] += 1, cnt += 1;
	}
	
	return cnt == n;
}


int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s1;
		cin >> s1;
		
		string s2(s1.rbegin(), s1.rend());
		
		for(int i = n; i > 0; i--) {
			if (can(s1, i) || can(s2, i)) {
				cout << i << endl;
				break;
			}
		}
	}
}