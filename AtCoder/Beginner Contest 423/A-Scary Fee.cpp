#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x;
	cin >> x;
	
	int c;
	cin >> c;
	
	int q = x / (1000+c);
	
	cout << 1000 * q << "\n";
}