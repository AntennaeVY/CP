#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int k, n;
		cin >> k >> n;
		
		
		int diff = 1, num = 1, qty = 1;
		cout << 1 << " ";
		
		while(qty < k)  {
			if (num + diff <= n && n - (num+diff) >= k-qty-1) {
				num += diff;
				diff++;

				cout << num << " ";
			} else {
				cout << ++num << " ";
			}
			
			qty++;
		}
		
		cout << endl;
	}
}