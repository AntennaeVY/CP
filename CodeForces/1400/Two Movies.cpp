#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		vector<int> p(3);
		
		int x=0, y=0;
		
		for(int i=0; i < n; i++) {
			if (a[i] == b[i])
				p[a[i] + 1]++;
			else if (a[i] > 0)
				x++;
			else if (b[i] > 0)
				y++;
		}
		
		while(p[0]) {
			if (x > y)
				x--;
			else
				y--;
			
			p[0]--;
		}
		
		while(p[2]) {
			if (x < y)
				x++;
			else
				y++;
				
			p[2]--;
		}
		
		cout << min(x, y) << endl;
	}
}