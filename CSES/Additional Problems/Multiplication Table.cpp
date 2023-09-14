#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	
	long long l=0, r=n*n;
	
	while(l+1 < r) {
		long long mid = l + (r-l)/2;
		long long cnt = 0;
		
		for(int i=1; i <= min(n, mid); i++) {
			cnt += min(n, mid/i);
		}
		   
		if (cnt >= (n*n + 1)/2)
			r = mid;
		else
			l = mid;
	}
	
	cout << r << endl;
}