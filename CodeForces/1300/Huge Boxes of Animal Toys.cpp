#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		
		vector<bool> can(4);
		
		if (b == 0 && c == 0) {
			if (a%2)
				can[0] = true;
			else
				can[3] = true;
		} else if (a == 0 && d == 0) {
			if (b%2) 
				can[1] = true;
			else 
				can[2] = true;
		} else {
			if ((a + b)%2) {
				can[0] = true;
				can[1] = true;
			} else {
				can[2] = true;
				can[3] = true;
			}
		}
		
		for(int i=0; i < 4; i++) {
			if (can[i])
				cout << "Ya" << " ";
			else
				cout << "Tidak" << " ";
		}
		
		cout << endl;
	}
}