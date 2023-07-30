#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		
		string d;
		cin >> d;
		
		map<pair<int, int>, map<string, bool>> mp;
		
		bool ok = true;
		int i=i1, j=j1, ans = 0;
		
		while(true) {
			if (i == i2 && j == j2)
				break;
				
			if (mp[{i, j}][d]) {
				ok = false;
				break;
			}
			
			mp[{i, j}][d] = true;
			
			if (d == "DL") {
				if (i+1 > n && j-1 < 1)
					d = "UR", ans++;
				else if (i+1 > n)
					d = "UL", ans++;
				else if (j-1 < 1)
					d = "DR", ans++;
				else
					i++, j--;
			} else if (d == "DR") {
				if (i+1 > n && j+1 > m)
					d = "UL", ans++;
				else if (i+1 > n)
					d = "UR", ans++;
				else if (j+1 > m)
					d = "DL", ans++;
				else
					i++, j++;
			} else if (d == "UL") {
				if (i-1 < 1 && j-1 < 1)
					d = "DR", ans++;
				else if (i-1 < 1)
					d = "DL", ans++;
				else if (j-1 < 1)
					d = "UR", ans++;
				else
					i--, j--;
			} else if (d == "UR") {
				if (i-1 < 1 && j+1 > m)
					d = "DL", ans++;
				else if (i-1 < 1)
					d = "DR", ans++;
				else if (j+1 > m)
					d = "UL", ans++;
				else
					i--, j++;
			}
		}
		
		cout << (ok ? ans : -1) << endl;
	}
}