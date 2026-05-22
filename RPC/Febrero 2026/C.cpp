#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x;
	cin >> x;
	
	cout << (x - (1 << __lg(x))) * 2 << "\n";
}