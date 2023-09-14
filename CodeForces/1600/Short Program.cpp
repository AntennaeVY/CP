#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	// 0: noop, 1: turn on, 2: turn off, 3: flip
	vector<unsigned int> bits(10, 0);
	
	unsigned int AND=1023, OR=0, XOR=0;
	
	while(n--) {
		char t;
		cin >> t;
		
		unsigned int c;
		cin >> c;
		
		if (t == '|') {
			for(int i=0; i < 10; i++) {
				if (c & (1 << i))
					bits[i] = 1;
			}
		} else if (t == '&') {
			for(int i=0; i < 10; i++) {
				if ((c & (1 << i)) == 0)
					bits[i] = 2;
			}
		} else {
			for(int i=0; i < 10; i++) {
				if (c & (1 << i))
					bits[i] ^= 3;
			}
		}
	}
	
	for(int i=0; i < 10; i++) {
		if (bits[i] == 1)
			OR |= (1 << i);
		else if (bits[i] == 2)
			AND ^= (1 << i);
		else if (bits[i] == 3)
			XOR |= (1 << i);
	}
	
	cout << 3 << endl;
	cout << "| " << OR << endl;
	cout << "& " << AND << endl;
	cout << "^ " << XOR << endl;
}