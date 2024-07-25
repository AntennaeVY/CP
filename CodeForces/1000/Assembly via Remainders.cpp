#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		 int n;
		 cin >> n;
		 
		 vector<int> x(n-1);
		 for(auto &xi : x) cin >> xi;
		 
		 int ai = 10000;
		 
		 cout << ai << " ";
		 
		 for(int i=0; i < n-1; i++) {
		 	ai += x[i];
		 	cout << ai << " ";
		 } 
		 
		 cout << endl;
	}
}