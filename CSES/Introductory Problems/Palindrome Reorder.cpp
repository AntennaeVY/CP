#include<bits/stdc++.h>
using namespace std;

string construct(string &s, vector<int> &c) {
	int n = s.size();
	string ans(n, '?');

	char x = '?';
	
	int j = 0;
	for(int i=0; i < 26; i++) {
		if (c[i] == 0)
			continue;
	
		while (c[i] >= 2 && j <= n/2 - (n % 2)) {
			ans[j] = 'A' + i;
			ans[n-j-1] = 'A' + i;
			
			c[i] -= 2, j++;
		}
		
		if (c[i] % 2) 
			x = 'A' + i;
	}
	
	if (n % 2) {
		ans[n/2] = x;
	}
	
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	int n = s.size();
	
	vector<int> c(26);
	for(auto &ch : s)
		c[ch - 'A']++;
		
	int odd = 0;
	for(int i=0; i < 26; i++) {
		odd += c[i] % 2;
	}
	
	if (n % 2 == odd) 
		cout << construct(s, c) << "\n";
	else
		cout << "NO SOLUTION\n";
}