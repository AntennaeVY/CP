#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int, int> cnt;
		vector<int> b(n+1, 0);
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			cnt[x]++;
		}
		
		b[1] = cnt[1];
		
		for(int i=2; i <= n; i++) {
			b[i] += cnt[1] + cnt[i];
			
			for(int j=2; j*j <= i; j++) {
				if (i % j)
					continue;
				
				b[i] += cnt[j];
				
				if (j*j != i)
					b[i] += cnt[i/j];
			}
		}
		
		cout << *max_element(b.begin(), b.end()) << endl;
	}
}