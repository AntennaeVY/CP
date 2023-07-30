#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
	if (a < b)
		swap(a,b);
	
	if (b==0) return a;

	return gcd(b, a%b);
}

main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;
    
    vector<int> greatest(2);
    greatest[0] = a[0];
    greatest[1] = a[1];
	
	for(int i=0; i < n; i++) {
		greatest[i%2] = gcd(greatest[i%2], a[i]);
	}

	int ans = 0;
	
	for(int i=0; i < 2; i++) {
		if (greatest[i] == 1) continue;
		
		bool ok = true;
		
		for(int j=1-i; j < n; j+=2) {
			if (a[j] % greatest[i] == 0)
				ok = false;
		}
		
		if (ok) ans = greatest[i];
	}
	
	
	cout << ans << endl;
  }
}