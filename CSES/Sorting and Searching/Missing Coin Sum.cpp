#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	sort(a.begin(), a.end());
	
	if (a[0] != 1) {
		cout << 1 << endl;
		return 0;
	}
	
	long long sum = 1;
	
	for(int i=1; i < n; i++) {
		if (a[i] > sum+1)
			break;
		
		sum += a[i];
	}
	
	cout << sum+1 << endl;
}