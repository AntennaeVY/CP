#include<bits/stdc++.h>
using namespace std;

int main() {
	int s;
	cin >> s;
	
	for(int i=100; i >= 0; i--) {
		for(int j=100-i; j >= 0; j--) {
			for(int k=100-i-j; k >= 0; k--) {
				for(int l=100-i-j-k; l >= 0; l--) {
					long long ans = i * 1000 + j * 100 + k * 10 + l;
					
					if (ans != s || i + j + k + l != 100)
						continue;
						
					cout << "Perfect: " << i << endl;
					cout << "Great: " << j << endl;
					cout << "Good: " << k << endl;
					cout << "Bad: " << l << endl;
					
					return 0;
				}
			}
		}
	}
	
	cout << "NO SOLUTION" << endl;
}