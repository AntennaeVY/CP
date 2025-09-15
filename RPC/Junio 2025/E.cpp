#include<bits/stdc++.h>
using namespace std;

bool is_valid(string &s) {
	if (s.back() != 'O')
		return false;
		
	if (s.find("OO") != string::npos)
		return false;
		
	if (s.find("O") == string::npos)
		return false;
		
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	if (!is_valid(s)) {
		cout << "INVALID\n";
		return 0;
	}
	
	int m = s.size();
	long long ans = (1LL << 62);
	reverse(s.begin(), s.end());
	
	for(long long i=8; i < (1LL<<49); i*=2) {
		bool can = true;
		long long x = i;
		
		for(int j=0; j < m; j++) {
			if (s[j] == 'O') {
				if ((x-1) % 3 != 0) {
					can = false;
					break;
				}
					
				x = (x-1)/3;
			}
			
			if (s[j] == 'E') {
				x *= 2;
				
				if (x > (1LL << 62)) {
					can = false;
					break;
				}
			}
		}
		
		if (can)
			ans = min(ans, x);
	}
	
	cout << ans << "\n";
	return 0;
}