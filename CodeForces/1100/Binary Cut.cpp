#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int cnt = 1;
		
		for(int i=1; i < s.size(); i++) {
			if (s[i] != s[i-1])
				cnt++;
		}
		
		if (s.find("01") != string::npos)
			cnt--;
			
		cout << cnt << endl;
	}
}