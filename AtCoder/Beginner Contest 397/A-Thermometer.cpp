#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	double x;
	cin >> x;
	
	if (x >= 38) 
		cout << 1 << endl;
	else if (x >= 37.5) 
		cout << 2 << endl;
	else 
		cout << 3 << endl; 
}