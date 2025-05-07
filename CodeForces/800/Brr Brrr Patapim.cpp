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
		
		vector<int> ans(2*n + 1);
		set<int> s;
		
		for(int i=1; i <= 2*n; i++)
			s.insert(i);
		
		for(int i=1; i <= n; i++) {
			for(int j=1; j <= n; j++) {
				int x;
				cin >> x;
				
				ans[i+j] = x;
				s.erase(x);
			}
		}
		
		ans[1] = *s.begin();
		
		for(int i=1; i <= 2*n; i++)
			cout << ans[i] << " ";
		cout << endl;
		
	}
}