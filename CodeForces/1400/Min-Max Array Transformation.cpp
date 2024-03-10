#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	for(int j=1; j <= t; j++) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;

		vector<vector<int>::iterator> m(n+1), M(n);
				
		for(int i=0; i < n; i++) {
			m[i] = lower_bound(b.begin(), b.end(), a[i]);
		}
	
		vector<int> pos;
		
		for(int i=1; i < n; i++) {
			if (b[i-1] < a[i])
				pos.push_back(i);
		}
		
		for(int i=0; i < n; i++) {
			auto it = upper_bound(pos.begin(), pos.end(), i);
			
			if (it == pos.end())
				M[i] = prev(b.end());
			else
				M[i] = b.begin() + *it - 1;
		}
		
		for(int i=0; i < n; i++) {
			cout << *m[i] - a[i] << " ";
		}
		
		cout << endl;
		
		for(int i=0; i < n; i++) {
			cout << *M[i] - a[i] << " ";
		}
		
		cout << endl;
		
	}
}