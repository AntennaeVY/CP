#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);	
	
	set<char> S;
	for(char c : s) S.insert(c);
	for(char c : {'{', ',', ' ', '}'}) S.erase(c);
	
	cout << S.size() << endl;	
}