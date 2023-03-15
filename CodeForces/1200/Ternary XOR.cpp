#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string x;
		cin >> x;
		
		bool diff = false;
		string num1(n, '0'), num2(n, '0');
		
		for(int i=0; i < n; i++) {
			if (x[i] == '1' && !diff) {
				num1[i] = '1', num2[i] = '0';
				diff = true;
			} else if (x[i] == '1') {
				num2[i] = '1';
			}
			
			if (x[i] == '2' && !diff) {
				num1[i] = num2[i] = '1';
			} else if (x[i] == '2'){
				num2[i] = '2';
			}
		}
		
		cout << num1 << endl;
		cout << num2 << endl;
	}
}