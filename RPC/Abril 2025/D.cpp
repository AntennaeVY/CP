#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<bool> v(2*n, true);
	vector<int> a(n);
	set<int> s;
	
	for(auto &ai : a) {	
		cin >> ai;
		ai--;
		
		v[ai] = false;
	}
	
	for(int i=0; i < 2*n; i++)
		if (v[i])
			s.insert(i);
			
	set<int> s2 = s;
		
	int mx = 0;
	for(int i=0; i < n; i++) {
		auto it = s.lower_bound(a[i]);
		
		if (it == s.begin()) {
			s.erase(prev(s.end()));
		} else {
			s.erase(prev(it));
			mx++;
		}
	}
	
	s = s2;
	
	int mn = 0;
	for(int i=0; i < n; i++) {
		auto it = s.lower_bound(a[i]);
		
		if (it == s.end()) {
			s.erase(s.begin());
			mn++;
		} else {
			s.erase(it);
		}
	}
	
	cout << mn << " " << mx << endl;
}