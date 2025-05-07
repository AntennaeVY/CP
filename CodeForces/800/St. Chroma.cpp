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
		
		vector<int> p(n);
		
		if (x < n)
			p[n-1] = x;
		else
			p[n-1] = n-1;
		
		for(int i=0; i < n-1; i++) {
			if (i >= x)
				p[i] = i+1;
			else
				p[i] = i;
		}
		
		for(auto &pi : p)
			cout << pi << " ";
		cout << endl;
	}
}