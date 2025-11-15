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
		
		int cnt = 0;
		
		// find l
		int L=0, r=n+1;
		while(L + 1 < r) {
			int m = L + (r-L)/2;
			
			int x, y;
			
			cout << "1 1 " << m << endl;
			cin >> x;
			
			cout << "2 1 " << m << endl;
			cin >> y;
			
			if (x != y)
				r = m;
			else
				L = m;
				
			cnt+=2;
		}
		
		int x, y;
		cout << "1 1 " << n << endl;
		cin >> x;
			
		cout << "2 1 " << n << endl;
		cin >> y;
	
		int s = abs(x-y);
		
		cnt += 2;
		assert(cnt <= 40);
		
		// cout << L << " " << R << endl;
		cout << "! " << L+1 << " " << L+s << endl;
	}
}