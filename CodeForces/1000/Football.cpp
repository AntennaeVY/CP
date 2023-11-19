#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	map<string, int> m;
	
	while(n--) {
		string s;
		cin >> s;
		
		m[s]++;
	}
	
	int ans_i = 0;
	string ans;
	
	for(auto &[x, y] : m) {
		if (y > ans_i)
			ans = x, ans_i = y;
	}
	
	cout << ans << endl;
}