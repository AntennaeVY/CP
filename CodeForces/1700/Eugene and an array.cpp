#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	long long ans = 0;
	vector<long long> p(n+1, 0);
	
	for(int i=0; i < n; i++) {
		p[i+1] = p[i] + a[i];
	}

	int last = 0;	
	set<long long> s;
	
	for(int i=0; i < n; i++) {
		s.insert(p[i]);
		last = max(last, i);
		
		while(last < n && !s.count(p[last+1])) {
			last++;
			s.insert(p[last]);
		}
		
		ans += last - i;
		s.erase(p[i]);
	}
	
	cout << ans << endl;
}