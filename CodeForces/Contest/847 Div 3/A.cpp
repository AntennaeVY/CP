#include<bits/stdc++.h>
using namespace std;

const string pi = "314159265358979323846264338327";

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int i;
		for(i=0; i < 30; i++) {
			if (s[i] != pi[i]) {
				break;
			}
		}	
		
		cout << i << endl;	
	}
}