#include<bits/stdc++.h>
using namespace std;

int get_div_count(int x, int div) {
	int cnt = 0;
	
	while(x % div == 0) {
		cnt++;
		x /= div;
	}
	
	return cnt;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,m;
		cin >> n >> m;
		
		long long add = 1;
		
		int div5 = get_div_count(n, 5);
		int div2 = get_div_count(n, 2);
		
		if (div5 > div2)
			while(add * 2 <= m && div5 > div2) {
				add *= 2;
				div2++;
			}
			
		if (div2 > div5)
			while(add * 5 <= m && div2 > div5) {
				add *= 5;
				div5++;
			}
			
		while(add * 10 <= m) add *= 10;
		
		if (add * n == n) {
			cout << 1LL*n*m << endl;
		}
		else {
			for(int i=m/add; i > 1; i--) {
				while(add * i <= m) add *= i;
			}
			
			cout << add * n << endl;
		}
	}
}