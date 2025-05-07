#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k;
	string s;
	
	cin >> k >> s;
	
	int n = s.size();
	
	if (k == 2) {
		int a = 0, b = 0;
		string s1 = "", s2 = "";
		
		for(int i=0; i < n; i++) {
			s1 += (i % 2 == 0 ? '0' : '1');
			s2 += (i % 2 == 0 ? '1' : '0');
		}
		
		for(int i=0; i < n; i++) {
			a += (s[i] != s1[i]);
			b += (s[i] != s2[i]);
		}
		
		if (a < b)
			cout << a << " " << s1 << endl;
		else
			cout << b << " " << s2 << endl;
			
		return 0;
	}
	
	vector<pair<int,int>> v;
	
	int start = 0;
	
	for(int i=1; i < n; i++) {
		if (s[i] != s[i-1]) {
			v.push_back({start, i-1});
			start = i;
		}
	}
	
	v.push_back({start, n-1});
	
	int ans = 0;
	
	for(auto &[x, y] : v) {
		if (y-x+1 < k)
			continue;
			
		int i = x+k-1;
		
		while(i < y) {
			s[i] ^= '1'^'0';
			ans++;
			
			i += k;
		}
		
		if ((y-x+1 )% k == 0) {
			s[y-1] ^= '1'^'0';
			ans++;
		}
		
	}
	
	cout << ans << " " << s << endl;
}