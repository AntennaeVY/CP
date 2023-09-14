#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	
	int n, tmax;
	cin >> n >> tmax;
	
	vector<int> c(n);
	for(auto &ci : c) cin >> ci;
	
	auto check = [&](int k) {
		priority_queue<int, vector<int>, greater<int>> pq;
		
		for(int i=0; i < k; i++) {
			pq.push(c[i]);
		}
		
		int next = k, t=0;
		
		while(!pq.empty()) {
			t++;
			
			while (!pq.empty() && pq.top() == t)
				pq.pop();
				
			if (pq.size() < k && next < n)
				pq.push(t+c[next++]);
		}
		
		return t <= tmax;
	};
	
	int l=0, r = n;
	
	while(l + 1 < r) {
		int k = l+(r-l)/2;
		
		if (check(k))
			r = k;
		else
			l = k;
	}
	
	cout << r << endl; 
}