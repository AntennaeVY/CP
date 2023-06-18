#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int cnt=1;
	string ans = "";
	
	for(int i=0; i < n; i+=cnt) {
		ans += s[i];
		cnt++;
	}
	
	cout << ans << endl;
}