#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	sort(a.begin(), a.end());
	
	for(auto ai : a)
		cout << ai << " ";
	
	cout << endl;
}