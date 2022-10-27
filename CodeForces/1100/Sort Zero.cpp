#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		unordered_map<int,int> p;
		set<int> s;
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
			p[a[i]] = i;
		}
		

		bool ok = true;
		int lastGood = -1;
		
		for(int i=n-2; i >= 0; i--) {
			if (a[i] > a[i+1] && ok) {
				ok = false;
				lastGood = i+1;
			}
			
			if (ok) continue;
				
			if (p[a[i]] >= lastGood) {
				lastGood = p[a[i]] + 1;
			} 
	
		}
	
		for(int i=0; i < lastGood; i++) {
			s.insert(a[i]);
		}
		
		cout << s.size() << endl;
	}
}