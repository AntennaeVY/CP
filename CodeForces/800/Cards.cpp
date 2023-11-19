#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int N=0, Z=0;
	
	for(int i=0; i < n; i++) {
		if (s[i] == 'n')
			N++;
		
		if (s[i] == 'z')
			Z++;
	}
	
	for(int i=0; i < N; i++) {
		cout << 1 << " ";
	}
	
	for(int i=0; i < Z; i++) {
		cout << 0 << " ";
	}
	
	cout << endl;
}