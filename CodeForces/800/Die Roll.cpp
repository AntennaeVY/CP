#include<bits/stdc++.h>
using namespace std;

int main() {
	int Y, W;
	cin >> Y >> W;
	
	int b = 6;
	int a = 7 - max(Y, W);
	
	if (a % 2 == 0)
		a /= 2, b /= 2;
		
	if (a % 3 == 0)
		a /= 3, b /= 3;
		
		
	cout << a << "/" << b << endl;
}