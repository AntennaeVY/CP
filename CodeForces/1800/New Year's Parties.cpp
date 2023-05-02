#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	
	vector<int> x(n);
	for(auto &xi : x) cin >> xi;
	
	map<int, int> m;
	set<int> mx;
	
	sort(x.begin(), x.end());
	
	for(int i=0; i < n; i++) {
		if (!mx.count(x[i] - 1))
			mx.insert(x[i] - 1);
		else if (!mx.count(x[i]))
			mx.insert(x[i]);
		else
			mx.insert(x[i]+1);
			
		m[x[i]]++;
	}
	
	int mn = 0;
	
	for(int i=1; i <= n; i++) {
		if (!m[i])
			continue;
		
		mn++;
		i+=2;
	}
	
	cout << mn << " " << mx.size() << endl;
}