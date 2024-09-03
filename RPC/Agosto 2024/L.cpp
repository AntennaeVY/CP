#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int n = s.size();
	int m = 0;
	
	while(32*(1 << m) < n) m++;
	
	for(int i=0; i <= m; i++) {
		cout << "long";
		
		if (i != m)
			cout << " ";
	}
	
	cout << endl;
}