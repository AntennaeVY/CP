#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> t;
	for(int i=0; i < n; i++) {
		int a, d;
		cin >> a >> d;
		
		t.emplace_back(a, d);
	}
	
	sort(t.begin(), t.end());
	
	long long ans = 0;
	long long time = 0;
	
	for(int i=0; i < n; i++) {
		time += t[i].first;
		ans += t[i].second - time;
	}
	
	cout << ans << endl;
}