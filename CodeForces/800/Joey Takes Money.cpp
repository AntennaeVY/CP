#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		long long ans = 1;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			ans *= x;
		}
		
		ans += n-1;
		
		cout << 2022*ans << endl;
	}
}