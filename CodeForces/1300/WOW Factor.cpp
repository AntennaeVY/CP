#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	vector<int> prefix_sum(s.size(), 0), suffix_sum(s.size(), 0);
	
	for(int i=1; i < s.size(); i++) {
		prefix_sum[i] = prefix_sum[i-1];
		
		if (s[i] == 'v' && s[i-1] == 'v') {
			prefix_sum[i] += 1;
		}
	}
	
	for(int i=s.size()-2; i >= 0; i--) {
		suffix_sum[i] = suffix_sum[i+1];
		
		if (s[i] == 'v' && s[i+1] == 'v') {
			suffix_sum[i] += 1;
		}
	}
	
	long long ans = 0;
	
	for(int i=1; i < s.size()-1; i++) {
		if (s[i] == 'o')
			ans += 1LL*prefix_sum[i-1]*suffix_sum[i+1];
	}
	
	cout << ans << endl;
}