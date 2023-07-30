#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	cout << 7 + 3*(n-1) << endl;
		
	int x=0, y=0;
	for(int i=0; i < n+1; i++) {
		cout << x << " " << y << "\n";
		cout << x << " " << y+1 << "\n";
		cout << x+1 << " " << y << "\n";
		
		x++, y++;
	}
	
	cout << x << " " << y << endl;
}