#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		
		cout << s1.substr(0, 1) + s2.substr(0, 1) + s3.substr(0,1) << endl;
	}
}