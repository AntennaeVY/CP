#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		int last = 0, inv = 0;
		for(int i=0; i < n; i++) {
			if (a[i] != b[i])
				last = i;
		}
		
		for(int i=last; i < n; i++) {
			if (a[i] == b[i] && a[i] == 1)
				inv++;
		}
	

		
		vector<int> ans = {inv % 2, inv % 2};
		for(int i=0; i < n; i++) {
			int turn = i % 2;
			
			if (a[i] == b[i]) 
				continue;
			
			if (ans[1 - turn] % 2) {
				if (turn == 0 && a[i] == 1)
					swap(a[i], b[i]);
				
				if (turn == 1 && b[i] == 1)
					swap(a[i], b[i]);
			} else if (ans[turn] % 2 == 0){
				if (turn == 0 && b[i] == 1)
					swap(a[i], b[i]);
					
				if (turn == 1 && a[i] == 1)
					swap(a[i], b[i]);
			}
			
			if (i > last)
				break;
			
			ans[0] += a[i];
			ans[1] += b[i];
				
		}

		int x = ans[0] % 2, y = ans[1] % 2;
		
		if (x == y) {
			cout << "Tie\n";
		} else if (x > y) {
			cout << "Ajisai\n";
		} else {
			cout << "Mai\n";
		}
	}
}