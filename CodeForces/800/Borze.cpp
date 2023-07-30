#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size();

	string ans = "";

	for(int i=0; i < n; i++) {
		if (s[i] == '.')
			ans += '0';
		else if (s[i] == '-')
			ans += (s[i+1] == '.' ? '1' : '2'), i++;
	}

	cout << ans << endl;
}