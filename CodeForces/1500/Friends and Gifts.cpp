#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	set<int> s1, s2;
	for(int i=1; i <= n; i++) {
		s1.insert(i);
		s2.insert(i);
	}
	
	for(int i=0; i < n; i++) {
		if (a[i] == 0)
			continue;
			
		s1.erase(i+1);
		s2.erase(a[i]);
	}

	vector<int> p, q;
	
	while(!s2.empty()) {
		p.push_back(*s2.begin());
		q.push_back(*s1.begin());
		
		s2.erase(s2.begin());
		s1.erase(s1.begin());
	}
	
	for(int i=0; i < p.size(); i++) {
		if (p[i] == q[i])
			swap(p[i], p[(i+1) % p.size()]);
	}
	
	int j=0;
	
	for(int i=0; i < n; i++) {
		if (a[i] != 0)
			continue;
			
		a[i] = p[j++];
	}
	
	for(auto x : a)
		cout << x << " ";
}