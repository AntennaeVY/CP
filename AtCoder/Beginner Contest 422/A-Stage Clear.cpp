#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	int stage = s[2] - '0';
	int world = s[0] - '0';
	
	if (stage == 8)
		world++;
		
	stage = (stage) % 8 + 1; 
	
	cout << world << "-" << stage << "\n";
}