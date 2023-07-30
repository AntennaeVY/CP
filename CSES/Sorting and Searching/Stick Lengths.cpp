#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> p(n); 
	
	for(int i=0; i < n; i++) {
		cin >> p[i];
	}
	
	sort(p.begin(), p.end());
	
	long long ans = 0;
	
	for(int i=0; i < n; i++) {
		ans += abs(p[n/2] - p[i]);
	}
	
	cout << ans << endl;
}