#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	if (t < 49)
		cout << "TOO COLD";
	else if (t > 60)
		cout << "TOO HOT";
	else
		cout << "ACCEPTED";
}