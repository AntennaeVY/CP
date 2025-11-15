#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	map<int,int> m;
	
	for(int i=0; i < 5; i++) {
		m[s[i]]++;
	}
	
	if (m.size() == 2 && (m.begin()->second == 2 || m.begin()->second == 3))
		cout << "YES\n";
	else
		cout << "NO\n"; 
}