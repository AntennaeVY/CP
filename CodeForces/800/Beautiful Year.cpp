#include<bits/stdc++.h>
using namespace std;

int main() {
	int y;
	cin >> y;
	
	while(true) {
		string y_s = to_string(++y);
		set<char> s;
		
		for (char c : y_s) {
			s.insert(c);
		}
		
		if (s.size() == y_s.size())
			break;
	}
	
	cout << y << endl;
}