#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int q;
	cin >> q;
	
	while(q--) {
		int x;
		cin >> x;
		
		int l=-1, r = n-1;
		while(l + 1  < r) {
			int m = l + (r-l)/2;
			
			if (a[m] >= x)
				r = m;
			else
				l = m;
		}
		
		int h1 = (a[r] >= x ? r-1 : r);
		
		l=0, r=n;
		while(l+1 < r) {
			int m = l + (r-l)/2;
			
			if (a[m] <= x)
				l = m;
			else
				r = m;
		}
		
		int h2 = (a[l] <= x ? l+1 : l);
		
		if (h1 == -1)
			cout << "X";
		else
			cout << a[h1];
			
		cout << " ";
			
		if (h2 == n)
			cout << "X";
		else
			cout << a[h2];
			
		cout << "\n";
	}
}