#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e4 + 7;

string get_last(string &s) {
	string t = string(s);
	int n = s.size();
	
	for(int i=0; i < n; i+=2) {
		int x = stoi(s.substr(i, 2));
		
		if (x % 11 == 0)
			continue;
	
		for(int j=0; j <= 9; j++) {
			if (11*(j+1) >= x) {
				t[i] = '0' + j, t[i+1] = '0' + j;
				break;
			}
		}
		
		i+=2;
		
		for(int j=i; j < n; j+=2) {
			t[j] = '9', t[j+1] = '9';
		}
		
		break;
	}
	
	return t;
}

int get_count(string &s) {
	int n = s.size();
	int ans = 0;
	
	int ten = 1;
	
	for(int i=n-1; i >= 0; i-=2) {	
		ans += (s[i] - '0') * ten, ten *= 10;
		
		ans %= MOD, ten %= MOD;
	}
		
	return ans;
}

bool is_twin(string &s) {
	int n = s.size();
	
	bool ok = true;
	
	for(int i=1; i < n; i+=2) {
		ok &= (s[i] == s[i-1]);
	}
	
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string l, r;
	cin >> l >> r;
	
	if (r.size() % 2)
		r = "0" + r;
	
	if (l.size() % 2)
		l = "0" + l;
		
	string tr = get_last(r);
	string tl = get_last(l);
	
	
	int ans = (get_count(tr) - get_count(tl) + MOD) % MOD;
	
	if (is_twin(l))
		ans += 1;
		
	cout << ans % MOD << "\n";

}