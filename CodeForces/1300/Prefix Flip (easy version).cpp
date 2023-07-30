#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string a, b;
		cin >> a >> b;
		
		reverse(a.begin(), a.end());		
		reverse(b.begin(), b.end());
		
		int k = 0;
		vector<int> ans;
		
		for(int i=0; i < a.size()-1; i++) {
			a[i] = (ans.size()-k)%2 ? a[i]^'1'^'0' : a[i];
			
			if (a[i] == b[i]) {
				continue;
			}
			
			if (a[i] != a.back()) {
				ans.push_back(1);
				k++;
			}
			
			ans.push_back(a.size()-i);
			reverse(a.begin()+i, a.end());
			
			a[a.size()-1] = b[i];
			a[i] = b[i];
		}
		
		if (a.back() != b.back()) {
			ans.push_back(1);
			a[a.size()-1] = b.back();
		}
		
		cout << ans.size() << endl;
		
		for(auto x : ans) {
			cout << x << " ";
		}
		
		if (ans.size())
			cout << endl;
	}
}