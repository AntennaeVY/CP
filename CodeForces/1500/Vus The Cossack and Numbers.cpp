#include<bits/stdc++.h>
using namespace std;

using ll = long long;
 
int main() {
	int n;
	cin >> n;
	
	vector<double> a(n);
	vector<bool> can(n, false);
	
	ll sum_pos = 0, sum_neg = 0;
	
	for(int i=0; i < n; i++) {
		cin >> a[i];
		
		if (a[i] > 0)
			sum_pos += a[i];
		else 
			sum_neg -= a[i];
	
		if ((int)a[i] != a[i])
			can[i] = true;
	}
	
	int cnt = abs(sum_pos - sum_neg);
	bool fix_pos = sum_pos < sum_neg;
	
	for(int i=0; i < n; i++) {
		if (cnt == 0) {
			cout << (int)a[i] << endl;
			continue;
		}
		
		if (fix_pos && can[i] && a[i] > 0) {
			cout << (int)a[i] + 1 << endl;
			cnt--;
		} else if (!fix_pos && can[i] && a[i] < 0) {
			cout << (int)a[i] - 1 << endl;
			cnt--;
		} else {
			cout << (int)a[i] << endl; 
		}
	}
}
