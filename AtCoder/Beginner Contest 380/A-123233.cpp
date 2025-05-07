#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	int a = 0, b = 0, c = 0;
	
	for(auto &ch : s)
		a += ch == '1', b += ch == '2', c += ch == '3';
		
	cout << (a == 1 && b == 2 && c == 3 ? "Yes":"No") << endl;
}