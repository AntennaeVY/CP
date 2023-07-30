#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x, y;
		cin >> n >> x >> y;
		
		int diff = y-x, jump = 0, mx = 1e9;
		vector<int> div;
		
		for(int i=1; i*i <= diff; i++) {
			if (diff % i)
				continue;
			
			if (i+1 <= n)
				div.push_back(i);
			
			if (diff/i + 1 <= n)
				div.push_back(diff/i);
		}
		
		for(auto i : div) {
			int elem = 2 + i-1;
			int dist = diff / i;
				
			elem += x/dist - (x%dist == 0);
			
			if (elem >= n){
				jump = dist, mx = y;
				break;
			} else if (y + (n-elem)*dist < mx) {
				jump = dist, mx = y + (n-elem)*dist;
			}
		}
		
		for(int i=0; i < n; i++) {
			cout << mx << " ";
			mx -= jump;
		}
		
		cout << endl;
	}
}