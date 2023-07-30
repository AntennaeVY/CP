#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
	long long n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	int one = 0;
	while(one < n && s[one] != '1') one++;
	
	for(int i=one; i < n; i++) {
		if (s[i] == '1')
			continue;
			
		if (i-one <= k) {
			k -= (i-one);
			swap(s[i], s[one]);
			one++;
		} else {
			swap(s[i], s[i-k]);
			k = 0;
		}
	}
	
	cout << s << endl;
  }
}