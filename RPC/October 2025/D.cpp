#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	map<int,int> m;
	for(auto &si : s) m[si]++;
	
	int odd = 0;
	
	for(auto [x, c] : m) {
		odd += c % 2;
	}
	
	if (s.size() % 2 == odd)
		cout << "yes" << "\n";
	else
		cout << "no\n"; 
}