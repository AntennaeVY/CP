#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		string x, s;
		cin >> x >> s;
		
		int op = -1;
		
		for(int i=0; i < 6; i++) {
			if (x.find(s) != string::npos) {
				op = i;
				break;
			}
			
			x += x;
		}
		
		cout << op << endl;
	}
}