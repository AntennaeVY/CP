#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a,b,c;
		cin >> a >> b >> c;
		
		cout << (abs(a-b) + c*2 - 1)/(2*c) << endl;
	}
}