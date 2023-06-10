#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int cnt = 0;
	vector<bool> del(n, false);
	
	for(int i=0; i < n-1; i++) {
		int j=i+1;
		
		while(j < n && s[j] == s[i]) {
			del[j] = true;
			j++, cnt++;
		}
		
		i = j;
	}
	
	if ((n-cnt) % 2) {
		for(int i=n-1; i >= 0; i--) {
			if (!del[i]) {
				del[i] = true;
				break;
			}
		}
		
		cnt++;
	}
		
	string ans = "";
	
	for(int i=0; i < n; i++) {
		if (!del[i])
			ans += s[i];
	}
	
	cout << cnt << endl;
	cout << ans << endl;
}