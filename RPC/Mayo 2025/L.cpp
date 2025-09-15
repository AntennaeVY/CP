#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int q;
	cin >> q;
	
	multiset<int> l, r;
	int n = 0;
	
	while(q--) {
		int t;
		cin >> t;
		
		if (t == 1) {
			int v;
			cin >> v;
			
			if (n == 0) {
				l.insert(v);
				n++;
				continue;
			}
			
			if (v <= *prev(l.end()))
				l.insert(v);
			else
				r.insert(v);
			
			n++;
			
			while(l.size() > (n+1)/2) {
				r.insert(*prev(l.end()));
				l.erase(prev(l.end()));
			}
			
			while(r.size() > n/2) {
				l.insert(*r.begin());
				r.erase(r.begin());
			}
		}
		 
		if (t == 2) {
			int v;
			cin >> v;
			
			if (n == 0)
				continue;
			
			if (v <= *prev(l.end())) {
				if (l.find(v) == l.end())
					continue;
				
				l.erase(l.find(v));
			} else {
				if (r.find(v) == r.end())
					continue;
				
				r.erase(r.find(v));
			}
				
			n--;
			
			while(l.size() > (n+1)/2) {
				r.insert(*prev(l.end()));
				l.erase(prev(l.end()));
			}
			
			while(r.size() > n/2) {
				l.insert(*r.begin());
				r.erase(r.begin());
			}
		}
		
		if (t == 3) {
			if (n == 0) {
				cout << "Empty!" << "\n";
			} else if (n % 2) {
				cout << *prev(l.end()) << "\n";
			} else {
				cout << (*prev(l.end()) + *r.begin()) / 2 << "\n";
			}
		}
	}
}