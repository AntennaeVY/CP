#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int x = *max_element(a.begin(), a.end()), sum = 0;
	
	for(int i=0; i < n; i++) {
		sum += x - a[i];
	}
	
	cout << sum << endl;
}