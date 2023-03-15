#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int x[3];
		cin >> x[0] >> x[1] >> x[2];
		
		int mx = *max_element(x, x+3);
		int mx_cnt = count(x, x+3, mx);
		
		for(int y : x) {
			if (y < mx)
				cout << mx - y + 1 << " ";
			else
				cout << (mx_cnt != 1) << " ";
		}
		
		cout << endl;
	}
}