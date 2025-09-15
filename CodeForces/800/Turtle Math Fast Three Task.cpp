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
		
		vector<int> m(3);
		int sum = 0;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			m[x%3] += 1;
			sum += x%3;	
		}
		
		sum %= 3;
		
		if (sum == 0)
			cout << 0 << "\n";
		else if (sum == 2)
			cout << 1 << "\n";
		else
			cout << ( m[1] ? 1 : 2) << "\n"; 
	}
}