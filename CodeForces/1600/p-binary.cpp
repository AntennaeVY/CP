#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	
	if (p == 0) {
		cout << __builtin_popcount(n) << endl;
		return 0;
	}
	
	int ans = -1;
	
	for(int i=1; i < 32; i++) {
		int x = n-i*p;
		
		if (x <= 0)
			break;
			
		int max_bit_cnt = (x & 1);
		
		for(int j=1; j < 32; j++) {
			int mask = (1 << j);
			
			if ((x & mask) != 0)
				max_bit_cnt += j;
		}
		
		int min_bit_cnt = __builtin_popcount(x);
		
		if (min_bit_cnt <= i && i <= max_bit_cnt) {
			ans = i;
			break;
		}
	}
	
	cout << ans << endl;
}