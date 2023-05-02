#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int q;
	cin >> q;
	
	while(q--) {
		long long a,b,c;
		cin >> a >> b >> c;
		
		long long ans = (a + b + c);
		
		cout << ans/2 << endl;
	}
}