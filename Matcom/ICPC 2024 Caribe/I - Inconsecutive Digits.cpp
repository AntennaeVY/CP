#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	cout << a << " " << b << " ";
	
	string s = "";
	for(int i=0; i <= 9; i++) {
		if (i != a && i != b)
			s += to_string(i);
	}
	
	do {
		bool can = true;
		
		if (abs(s[0] - 48 - b) == 1)
			can = false;
		
		for(int i=1; i < s.size(); i++) {
			if (abs(s[i] - s[i-1]) == 1)
				can = false;
		}
		
		if (can)
			break;
		
	} while(next_permutation(s.begin(), s.end()));

	for(auto &ch : s)
		cout << ch << " ";
}