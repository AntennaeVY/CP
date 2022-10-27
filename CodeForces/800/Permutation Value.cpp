#include<bits/stdc++.h> 
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int a = n;
		int b = 1;
		
		cout << 1 << " ";
		
		for(int i=3; i <= n; i++) {
			cout << i << " ";
		}
		
		cout << 2 << endl;
	}
}