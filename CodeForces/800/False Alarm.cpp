#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int first = 0, last = 0;
		
		for(int i=0; i < n; i++)
			if (a[i])
				last = i;
				
		for(int i=n-1; i >= 0; i--)
			if (a[i])
				first = i;
				
		if (last - first + 1 > x)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	
}