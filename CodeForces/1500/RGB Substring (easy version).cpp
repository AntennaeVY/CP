#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int q;
	cin >> q;
	
	while(q--) {
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
	
		char chars[3] = {'R', 'G', 'B'};
		int mn = 1e9;
		
		for(int i=0; i <= n-k; i++) {
			for(int j=0; j < 3; j++) {
				int cnt = 0;
				
				for(int x=i; x-i+1 <= k; x+=3) {
					cnt += s[x] != chars[j%3]; 
				}
				
				for(int x=i+1; x-i+1 <= k; x+=3) {
					cnt += s[x] != chars[(j+1)%3];
				}
				
				for(int x=i+2; x-i+1 <= k; x+=3) {
					cnt += s[x] != chars[(j+2)%3];
				}
				
				mn = min(mn, cnt);
			}
		}
		
		cout << mn << endl;
	}
}