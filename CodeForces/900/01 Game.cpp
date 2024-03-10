#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int x = count(s.begin(), s.end(), '0');
		int y = s.size() - x;
		
		
		if (min(x, y) % 2 == 0)
			cout << "NET" << "\n";
		else
			cout << "DA" << "\n";
	}
}