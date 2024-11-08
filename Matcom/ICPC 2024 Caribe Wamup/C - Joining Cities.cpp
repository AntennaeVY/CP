#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	sort(a.begin(), a.end());
	
	long long sum = 0;
	
	for(int i=1; i < n; i++) {
		sum += abs(a[i] - a[i-1]);
	}
	
	cout << sum << endl;
}