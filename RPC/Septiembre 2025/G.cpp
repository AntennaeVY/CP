#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

vector<int> prefix_function(const string &s) {
	int n = s.size();
	vector<int> pi(n + 5);
	
	for(int i=1; i < n; i++) {
		int j = pi[i-1];
		
		while(j > 0 && s[i] != s[j])
			j = pi[j-1];
			
		if (s[i] == s[j])
			j++;
		
		pi[i] = j;
	}
	
	return pi;
}

vector<vector<int>> build_automaton(const string &s, const int k) {
	int n = s.size();
	vector<int> pi = prefix_function(s);
	vector<vector<int>> automaton(n + 5, vector<int>(k + 5));
	
	for(int i=0; i < n; i++) {
		for(int c=0; c < k; c++) {
			if (i > 0 && s[i] != 'a' + c)
				automaton[i][c] = automaton[pi[i-1]][c];
			else
				automaton[i][c] = i + (s[i] == 'a' + c);
		}
	}
	
	return automaton;
}

int binpow(int a, int b) {
	int result = 1;
	
	a %= MOD;
	
	while(b) {
		if (b & 1)
			result = (1LL * result * a) % MOD;
		
		a = (1LL * a * a) % MOD;	
		b >>= 1;
	}
	
	return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	auto automaton = build_automaton(s, k);

	vector<vector<int>> dp(n+5, vector<int>(s.size() + 5));
	dp[0][0] = 1;
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < s.size(); j++) {
			for(int c=0; c < k; c++) {
				int next = automaton[j][c];
				
				if (next == n)
					continue;
				
				dp[i+1][next] += dp[i][j];
				dp[i+1][next] %= MOD; 
			}
		}
	}
	
	int avoid = 0;
	
	for(int j=0; j < s.size(); j++)
		avoid += dp[n][j], avoid %= MOD;
	
	cout << (binpow(k, n) - avoid + MOD) % MOD << "\n";
}