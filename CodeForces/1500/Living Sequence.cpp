#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long k;
		cin >> k;
		
		string ans;
		
		while(k) {
			int dig = k % 9;
			
			if (dig >= 4)
				dig++;
				
			ans += (char)(48 + dig);
			k /= 9;
		}
		
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}