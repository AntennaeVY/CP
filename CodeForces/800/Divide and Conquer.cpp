#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int cnt = 1e9;
		long long sum = 0;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			int cnt2 = 0;
			int y = x;
			
			while(y%2 == x%2) {
				y/=2;
				cnt2++;
			}
			
			cnt = min(cnt, cnt2);
			sum += x;
		}
		
		cout << (sum%2 == 0 ? 0 : cnt) << endl;
	}
}