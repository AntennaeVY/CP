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
		
		int sum=0;
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			sum += abs(x);
		}
		
		cout << sum << "\n";
	}
}