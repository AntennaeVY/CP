#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int l=0, r=s.size()-1;
	
	vector<int> ops, ops2;
	
	while(l < r) {
		if (s[l] != '(') {
			l++;
			continue;
		}
		
		if (s[r] != ')') {
			r--;
			continue;
		}
		
		ops.push_back(l+1);
		ops2.push_back(r+1);
		
		l++;
		r--;
	}
	
	if (ops.size() != 0)
		cout << 1 << endl;
	
	cout << 2  * ops.size() << endl;
	
	for(auto i:ops) {
		cout << i << " ";
	}
	
	for(int i=ops2.size()-1; i >= 0; i--) {
		cout << ops2[i] << " ";
	}
	
	cout << endl;
}