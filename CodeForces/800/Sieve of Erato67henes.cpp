#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		
	
		
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int r=1;
		for(int i=0; i < n; i++)
			r *= a[i];
			
			
		cout << (r % 67 == 0 ? "YES" : "NO") << endl;
	}
}