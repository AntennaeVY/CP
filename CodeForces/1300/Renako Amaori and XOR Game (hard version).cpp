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
		
		vector<int> A(n), B(n);
		for(auto &ai : A) cin >> ai;
		for(auto &bi : B) cin >> bi;
		


		
		// for(auto &ai : a)
			// cout << ai << " ";
		// cout << endl;
// 		
		// for(auto &bi : b)
			// cout << bi << " ";
		// cout << endl;
		
		bool tie = true;
		
		for(int j=30; j >= 0; j--) {
			vector<int> a(A), b(B);
			
			for(int x = 0; x < n; x++) {
				a[x] &= (1 << j);
				b[x] &= (1 << j);
				
				a[x] = (a[x] >= 1);
				b[x] = (b[x] >= 1);
			}
		
			
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
			
			if (x > y) {
				tie = false;
				cout << "Ajisai\n";
				break;
			} else if (x < y) {
				tie = false;
				cout << "Mai\n";
				break;
			}
			
		}
		
		if (tie) {
			cout << "Tie\n";
		}
	}
}