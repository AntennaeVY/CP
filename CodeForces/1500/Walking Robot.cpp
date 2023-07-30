#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, b, a;
	cin >> n >> b >> a;
	
	vector<int> s(n);
	for(auto &si : s) cin >> si;
	
	int ans = n, A = a;
	
	for(int i=0; i < n; i++) {
		if (A == 0 && b == 0) {
			ans = i;
			break;
		}  
		
		if (s[i]) {
			if (A == a || b == 0)
				A--;
			else
				b--, A++;
		} else {
			if (A)
				A--;
			else
				b--;
		}
	}
	
	cout << ans << endl;
}