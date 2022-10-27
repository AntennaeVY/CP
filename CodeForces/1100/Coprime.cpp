#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b > a)
		swap(a,b);
	
	if (b == 0) return a;
	
	return gcd(b, a%b);
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(1001, 0);
		
		for(int i=0; i < n; i++) {
		    int x;
		    cin >> x;
		    
		    a[x] = i+1;
		}
		
		int ans = -1;
		
		for(int i=1000; i > 0; i--) {
			for(int j=i; j > 0; j--) {
				if (a[i] && a[j] && gcd(i, j) == 1)
					ans = max(ans, a[i]+a[j]);
			}
		}
		
		cout << ans << endl;
	}
}