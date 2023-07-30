#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	map<int, int> m;
	
	m[0] = 1;
	int n = s.size();
	
	int pow = 1, sum = 0;
	for(int i=n-1; i >= 0; i--) {
		sum = (sum + 1LL*(s[i] - 48)*pow) % 2019;
		
		m[sum]++;
		
		pow = (pow*10) % 2019;
	}
	
	long long ans = 0;
	
	for(auto &[_, c] : m) {
		ans += (1LL*c*(c-1))/2;
	}
	
	cout << ans << endl;
}