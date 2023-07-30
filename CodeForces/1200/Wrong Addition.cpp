#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long a, s;
		cin >> a >> s;
		
		if (a > s) {
			cout << -1 << endl;
			continue;
		} 
		
		bool ok = true;
		string ans = "";
		
		while(s || a) {
			int sd = s%10, ad = a%10;
			
			if (sd < ad)
				sd = s%100;

			if (sd - ad < 0 || sd - ad >= 10 || !s && a) {
				ok = false;
				break;
			}
				
			ans += to_string(sd-ad);
			
			a /= 10;
			s /= sd >= 10 ? 100 : 10;
		}
		
		while(ans.back() == '0' && ans.size() != 1)
			ans.pop_back();
			
		reverse(ans.begin(), ans.end());
		
		if (!ok)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
}