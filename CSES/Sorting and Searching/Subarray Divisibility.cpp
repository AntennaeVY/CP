#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	long long ans = 0, sum = 0;
	map<long long, long long> cnt;
	
	cnt[0] = 1;

	for(int i=0; i < n; i++) {
		sum += a[i];
		ans += cnt[(sum%n + n)%n];
		cnt[(sum%n + n)%n]++;
	}
	
	cout << ans << endl;
}