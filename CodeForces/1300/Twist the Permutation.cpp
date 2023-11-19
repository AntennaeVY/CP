#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int, int> idx;
		
		for(int i=0; i < n; i++) {
			idx[a[i]] = i+1;
		}
		
		vector<int> ans;
		
		for(int i=n; i >= 1; i--) {
			for(int j=1; j < i; j++) {
				idx[j] = ((idx[j] - idx[i]) % i + i) % i;
			}
			
			ans.push_back(idx[i]);
		}
		
		for(int i=n-1; i >= 0; i--) {
			cout << ans[i] % (n-i) << " ";
		}
		
		cout << endl;
	}
}