#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int n = s.size();
	
	for(int i=0; i < n; i++) {
		s[i] = tolower(s[i]);
	}
	
	string abc = s, cba = s;
	
	sort(abc.begin(), abc.end());
	sort(cba.rbegin(), cba.rend());
	
	cout << (s != abc && s != cba ? "no" : "yes") << endl;
}