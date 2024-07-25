#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> l(n), r(n);
	for(int i=0; i < n; i++) {
		cin >> l[i] >> r[i];
	}
	
	long long min_sum = 0, max_sum = 0;
	
	for(int i=0; i < n; i++) {
		min_sum += l[i];
		max_sum += r[i];
	}
	
	if (min_sum > 0 || max_sum < 0) {
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	
	long long need = 0 - min_sum;
	
	for(int i=0; i < n; i++) {
		long long move = min(need, 1LL * r[i] - l[i]);
		
		cout << l[i] + move << " ";
		
		need -= move;
	}
	
	cout << endl;
}