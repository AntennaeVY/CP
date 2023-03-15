#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	for(int i=4; i <= n; i++) {
		string s = to_string(i);
		int c = count(s.begin(), s.end(), '4') + count(s.begin(), s.end(), '7');
		
		if (c == s.size() && n % i == 0) { 
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
}