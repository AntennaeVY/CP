#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		bool ok = true;
		map<int, bool> unused1, unused2;
		unordered_map<int, int> m;
		vector<int> a(n), sorted_a(n);
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
			sorted_a[i] = i;
			
			if (++m[a[i]] > 2)
				ok = false;
				
			unused1[i+1] = true;
			unused2[i+1] = true;
		}
		
		if (m[1] > 1)
			ok = false;

		sort(sorted_a.begin(), sorted_a.end(), [&](const int i, const int j){ return a[i] < a[j]; });
		
		for(int i=0; i < n; i++) {
			if (a[sorted_a[i]] < i+1)
				ok = false;
		}
		
					
		if (!ok) {
			cout << "NO" << endl;
			continue;
		} else {
			cout << "YES" << endl;
		}
		
		unordered_map<int, bool> used1, used2;
		vector<int> p1(n, -1), p2(n, -1);
		
		for(int i=n-1; i >= 0; i--) {
			
			if (used1[a[sorted_a[i]]]) {
				p2[sorted_a[i]] = a[sorted_a[i]];
				used2[a[sorted_a[i]]] = true;
				unused2.erase(a[sorted_a[i]]);
			} else {
				p1[sorted_a[i]] = a[sorted_a[i]];
				used1[a[sorted_a[i]]] = true;
				unused1.erase(a[sorted_a[i]]);
			}	
		}
	
		
		for(int i=n-1; i >= 0; i--) {
			if (p1[sorted_a[i]] == -1) {
				p1[sorted_a[i]] = unused1.rbegin()->first;
				unused1.erase(unused1.rbegin()->first);
			} else {
				p2[sorted_a[i]] = unused2.rbegin()->first;
				unused2.erase(unused2.rbegin()->first);
			}
		}
		
		for(auto &pi : p1) 
			cout << pi << " ";
			
		cout << endl;
		
		for(auto &pi : p2)
			cout << pi << " ";
		
		cout << endl;
	}
}