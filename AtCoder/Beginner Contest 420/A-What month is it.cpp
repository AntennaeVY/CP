#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x, y;
	cin >> x >> y;
	
	int z = (x+y)%12;
	
	cout << (z ? z : 12) << "\n";
}