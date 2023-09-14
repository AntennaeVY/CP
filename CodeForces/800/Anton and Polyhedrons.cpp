#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	long long sum = 0;
	
	while(n--) {
		string s;
		cin >> s;
		
		switch(s[0]) {
			case 'T': 
				sum += 4;
				break;
			case 'C': 
				sum += 6;
				break;
			case 'O': 
				sum += 8;
				break;
			case 'D': 
				sum += 12;
				break;
			case 'I': 
				sum += 20;
				break;
		}
	}
	
	
	cout << sum << endl;
}