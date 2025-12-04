#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {	
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> p;
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++) {
				p.push_back(a[i] + a[j]);		
			}
		}
		
		sort(p.begin(), p.end());
		cout << p[k-1] << '\n';
		
		for(auto &pi : p)
			cout << pi << " ";
		cout << endl;
	}
}