#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	int n = s.size();
	
	map<char, char> inv = {
		{'0', '0'},
		{'1', '1'},
		{'2', '2'},
		{'3', 'E'},
		{'4', '?'},
		{'5', '5'},
		{'6', '9'},
		{'7', '?'},
		{'8', '8'},
		{'9', '6'},
		{'A', '?'},
		{'b', '?'},
		{'B', '?'},
		{'C', '?'},
		{'d', '?'},
		{'D', '?'},
		{'E', '3'},
		{'F', '?'}
	};
	
	int c = 0;
	for(int i=0; i < n/2; i++) {
		if (inv[s[i]] != s[n-i-1]) {
			if (inv[s[i]] != '?' || inv[s[n-i-1]] != '?')
				c += 1;
			else
				c += 2;
		}
	}
	
	if (n % 2 && inv[s[n/2]] != s[n/2])
		c++;
		
	cout << c << "\n";
}