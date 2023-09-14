#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	
	int mn = min(a,b);
	a -= mn, b -= mn;
	
	cout << mn << " " << (a+b)/2 << endl;
}