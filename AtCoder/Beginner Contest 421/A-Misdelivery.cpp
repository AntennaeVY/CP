#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<string> s(n);
	for(auto &si : s) cin >> si;
	
	int x;
	string y;
	cin >> x >> y;
	
	x--;
	
	cout << (s[x] == y ? "Yes" : "No") << "\n";
}