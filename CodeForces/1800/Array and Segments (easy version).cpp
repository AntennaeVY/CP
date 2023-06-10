#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<long long> a(n);
	for(auto &ai : a) cin >> ai;
	
	vector<pair<int, int>> s(m);
	for(auto &[li, ri] : s) cin >> li >> ri;
	
	long long ans = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()); 
	int idx = 0;
	
	for(int i=0; i < n; i++) {
		vector<long long> p(n+1, 0), b = a;
	
		for(int j=0; j < m; j++) {
			auto [l, r] = s[j];

			if (i >= l-1 && i <= r-1)
				continue;
				
			p[l-1] -= 1, p[r] += 1;
		}
		
		for(int j=0; j < n; j++) {
			p[j+1] += p[j];
			b[j] += p[j];
		}
		
		int curr = *max_element(b.begin(), b.end()) - *min_element(b.begin(), b.end());
		
		if (curr > ans) {
			idx = i;
			ans = curr;
			
		}
	}
	
	int cnt = 0;
	vector<int> ap;
	
	if (ans != *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end())) {
		for(int i=0; i < m; i++) {
			auto [l, r] = s[i];
			
			if (idx >= l-1 && idx <= r-1)
				continue;
				
			ap.push_back(i+1);
			cnt++;
		}
	}
	
	cout << ans << endl;
	cout << cnt << endl;
	for(auto api : ap)
		cout << api << " ";
}