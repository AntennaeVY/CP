#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	
	map<int, int> yellow;
	map<int, bool> out;
	
	while(Q--) {
		int c, x;
		cin >> c >> x;
		
		if (c == 1) {
			yellow[x]++;
			out[x] |= (yellow[x] == 2);
		} else if (c == 2) {
			out[x] = true;
		} else {
			cout << (out[x] ? "Yes" : "No") << endl;
		}
	}
}