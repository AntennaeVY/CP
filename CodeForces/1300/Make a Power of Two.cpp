#include<bits/stdc++.h>
using namespace std;

int lcp(string &a, string &b) {
	int n = a.size(), m = b.size();
	
	for(int i=0; i < min(n, m); i++) {
		if (a[i] != b[i])
			return i;
	}
	
	return min(n, m);
}

string parse_subsequence(string &s, int x) {
	int n = s.size();
	string ans = "";
	
	for(int i=0; i < n; i++) {
		if (x & (1 << i))
			ans += s[i];
	}
	
	return ans;
}

int main() {
	int t;
	cin >> t;
	
	vector<string> pows;
	for(long long i=1; i <= 1e18; i <<= 1) {
		pows.push_back(to_string(i));
	}
	
	while(t--) {
		string n;
		cin >> n;
		
		int ans = 1e9;
		for(auto &p : pows) {
			int i=0, j=0, cnt=0, x = n.size(), y = p.size();
			
			while(i < x && j < y) {
				if (n[i] == p[j])
					cnt++, j++;
					
				i++;
			}
			
			ans = min(ans, x - cnt + y - cnt);
		}
		
		cout << ans << endl;
	}
}