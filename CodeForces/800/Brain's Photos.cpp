#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	map<char, int> M;
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			char c;
			cin >> c;
			
			M[c]++;
		}
	}
	
	if (M['W'] + M['B'] + M['G'] == n*m) {
		cout << "#Black&White" << endl;
	} else {
		cout << "#Color" << endl;
	}
}