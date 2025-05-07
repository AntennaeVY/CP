#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int q;
		cin >> q;
		
		deque<long long> dq;
		
		bool rev = false;
		long long x = 0, n = 0;
		long long sn = 0, sr = 0, sum = 0;
		
		while(q--) {
			int s;
			cin >> s;
			
			if (s == 1) {
				sn = sn - 1LL * x * n + sum;
				sr = sr - sum + 1LL * x * n;
				
				if (rev) {
					dq.push_back(dq.front());
					dq.pop_front();
					
					x = dq.front();
				} else {
					dq.push_front(dq.back());
					dq.pop_back();
					
					x = dq.back();
				}
			}
			
			if (s == 2) {
				swap(sn, sr);
				
				rev = !rev;
				
				if (rev)
					x = dq.front();
				else
					x = dq.back();
			}
			
			if (s == 3) {
				int k;
				cin >> k;
				
				n++;
				
				sr = sr + sum + k;
				sn = sn + k * n;
				
				sum += k;
				
				if (rev) {
					dq.push_front(k);
				} else {
					dq.push_back(k);
				}
				
				x = k;
			}
			
			cout << sn << "\n";
		}
	}
}