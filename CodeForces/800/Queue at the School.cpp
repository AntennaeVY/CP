#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	
	string s;
	cin >> s;
	
	for(int k=0; k < t; k++) {
		string q = s;
		
		for(int i=1; i < n; i++) {
			if (s[i] == 'G' && s[i-1] == 'B')
				swap(q[i], q[i-1]);
		}
		
		s = q;
	}
	
	cout << s << endl;
}