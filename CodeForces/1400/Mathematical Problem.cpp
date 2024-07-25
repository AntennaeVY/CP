#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		if (n == 2) {
			cout << stoi(s) << endl;
			continue;
		}
		
		int ones = 0, zeros = 0, sum = 0;
		
		for(int i=0; i < n; i++) {
			sum += s[i] - '0';
			
			ones += (s[i] == '1');
			zeros += (s[i] == '0');
		}
		
		if (zeros && n > 3) {
			cout << 0 << endl;
			continue;
		}
		
		int mn = 1e9;
		
		for(int i=1; i < n; i++) {
			int x = (s[i-1] - '0') * 10 + (s[i] - '0');
			int t_ones = ones - (s[i-1] == '1') - (s[i] == '1');
			int t_zeros = zeros - (s[i-1] == '0') - (s[i] == '0');
			
			if (t_zeros) {
				mn = 0;
				break;
			}
			
			if (t_ones == n-2) {
				mn = min(mn, x);
				continue;
			}

			if (x == 1)
				x = 0;
				
			int c = sum - (s[i-1] - '0') - (s[i] - '0') - t_ones + x; 
			
			mn = min(mn, c);
		}
		
		cout << mn << endl;
	}
}
