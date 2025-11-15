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
		
		int x = 0, y = 0;
		for(int i=0; i < n; i++)
			x += (a[i] == 0), y += (a[i] == -1);
			
		cout << x + 2*(y%2) << "\n";
	}
}