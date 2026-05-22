#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	int n = s.size();
	
	bool can = false;
	
	for(int i=0; i < n-3; i++) {
		if (s.substr(i, 3) == "kth")
			can = true;
	}
	
	cout << (can ? "yes" : "no") << "\n";
}