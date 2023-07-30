#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		int n;
		cin >> n;
		
		vector<int> t(n);
		for(auto &ti : t) cin >> ti;
		
		if (count(t.begin(), t.end(), t[0]) == n) {
			cout << 1 << endl;
			
			for(int i=0; i < n; i++) {
				cout << 1 << " ";
			}
			
			cout << endl;
			continue;
		}
		
		if (n % 2 == 0) {
			cout << 2 << endl;
			
			for(int i=0; i < n; i++) {
				cout << i%2 + 1 << " ";
			}
			
			cout << endl;
			continue;
		}
		
		bool can_merge = (t[0] == t[n-1]);
		
		for(int i=1; i < n; i++) {
			can_merge |= (t[i] == t[i-1]);
		}
		
		if (can_merge) {
			cout << 2 << endl;
			
			bool merged_end = false;
			for(int i=0; i < n-1; i++) {
				
				if (can_merge)
					cout << i%2 + 1 << " ";
				else
					cout << (i-1)%2 + 1 << " ";
			
				if (t[i] == t[i+1] && can_merge) {
					cout << i%2 + 1 << " ";
					i++;		
					
					can_merge = false;
					merged_end = (i == n-1);
				}
			}
			
			if (can_merge)
				cout << 1;
			else if (!merged_end)
				cout << 2;
		
			cout << endl;		
		} else {
			cout << 3 << endl;
			
			for(int i=0; i < n-1; i++) {
				cout << i%2 + 1 << " ";
			}
			
			cout << 3 << endl;
		}
	}
}