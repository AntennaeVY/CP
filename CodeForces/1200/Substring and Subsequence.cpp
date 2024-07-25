#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int t;
	cin >> t;
	
	while(t--) {
		string a, b;
		cin >> a >> b;
	
		int n = a.size(), m = b.size();
		
		int mx = 0;
		
		for(int j = 0; j < m; j++) {
			int x = j;
			
			for(int i = 0; i < n; i++) {
				if (x < m && a[i] == b[x])
					x++;
			}
			
			if (x - j > mx)
				mx = x - j;
		}
		
		cout << n + m - mx << endl;
	}
}