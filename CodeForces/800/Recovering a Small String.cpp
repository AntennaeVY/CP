#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s = "";
		
		for(int i=1; i <= 26; i++) {
			for(int j=1; j <= 26; j++) {
				for(int k=1; k <= 26; k++) {
					if (i + j + k == n) {
						s += char('a' + i - 1);
						s += char('a' + j - 1);
						s += char('a' + k - 1);
						
						goto end;
					}
				}
			}
		}
		
		end:
			cout << s << "\n";
	}
}