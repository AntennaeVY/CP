#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> p(n);
	for(auto &pi:p) cin >> pi;
	
	long long sum = 0, ans = LLONG_MAX;
	
	for(int i=0; i < n; i++) {
		sum += p[i];
	}

	int mask = (1 << n) - 1;
	
	for(int i=0; i <= mask; i++) {
		long long current_sum = 0;
		int subset = mask ^ i;
		
		for (int j=0; j < n; j++) {
			if (subset >> j & 1)
				current_sum += p[j];
		}
		
		ans = min(ans, abs(sum-2*current_sum));
	}
	
	cout << ans << endl;
}