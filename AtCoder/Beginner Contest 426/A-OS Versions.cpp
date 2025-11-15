#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<string> v = {"Ocelot", "Serval", "Lynx"};
	string x, y;
	cin >> x >> y;
	
	int i = find(v.begin(), v.end(), x) - v.begin();
	int j = find(v.begin(), v.end(), y) - v.begin();
	
	cout << (i >= j ? "Yes" : "No") << "\n";
}