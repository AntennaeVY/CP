#include<bits/stdc++.h>
using namespace std;

bool good(long long mid, vector<int> &alarms, int x, int k) {
	long long sum = 0;
	
	for(int i=0; i < alarms.size(); i++) {
		if (alarms[i] <= mid)
		sum += (mid-alarms[i])/x + 1;
	}
	
	return sum < k;
}

int main() {
	int n, x, k;
	cin >> n >> x >> k;
	
	vector<int> t(n), alarms;
	map<int, int> m;
	for(auto &ti:t) cin >> ti;

	
	for(int i=0; i < n; i++) {
		if (m[t[i]%x] == 0) 
			m[t[i]%x] = t[i];
		else
			m[t[i]%x] = min(m[t[i]%x], t[i]);
	}
	
	for(auto it : m) {
		alarms.push_back(it.second);
	} 
	
	long long l=0, r=LLONG_MAX;
	
	while(l+1 < r) {
		long long mid = l+(r-l)/2;
		
		if (good(mid, alarms, x, k)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	
	cout << r << endl;
}