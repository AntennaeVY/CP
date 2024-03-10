#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s, f;
		cin >> s >> f;
		
		int a = 0, b = 0;
		
		for(int i=0; i < n; i++) {
			if (s[i] == '1' && f[i] == '0')
				a++;
			else if (s[i] == '0' && f[i] == '1')
				b++;
		}
		
		cout << max(a, b) << endl;
	}
}