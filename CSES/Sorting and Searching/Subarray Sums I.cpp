#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	long long ans = 0, sum = 0;
	map<long long, int> cnt;
	
	cnt[0] = 1;

	for(int i=0; i < n; i++) {
		sum += a[i];
		ans += cnt[sum - x];
		cnt[sum]++;
	}
	
	cout << ans << endl;
}