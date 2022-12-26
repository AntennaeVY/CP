#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		sort(a.begin()+1, a.end());
		
		for(int i=0; i < n; i++) {
			if (a[i] <= a[0])
				continue;
				
			a[0] = (a[0] + a[i] + 1)/2;
		}
		
		cout << a[0] << endl;
	}
}