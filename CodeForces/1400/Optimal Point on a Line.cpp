#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> x(n);
	for(auto &xi : x) cin >> xi;
	
	sort(x.begin(), x.end());
	
	cout << x[(n+1)/2 - 1] << endl;
}