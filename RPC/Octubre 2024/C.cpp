#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<bool> c(n+1), j(n+1);
	
	while(m--) {
		int p, l;
		cin >> p >> l;
		
		if (l == 1)
			c[p] = true;
		
		if (l == 2)
			j[p] = true;
	}
	
	for(int i=1; i <= n; i++) {
		if (c[i] && j[i])
			cout << i << endl;
	}
}