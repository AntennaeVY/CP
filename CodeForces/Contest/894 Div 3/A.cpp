#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<string> a(n);
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
		}
		
		string match = "vika";
		int index = 0;
		
		for(int j=0; j < m; j++) {
			bool ok = true;
			
			if (index == 4)
				break;
			
			for(int i=0; i < n; i++) {
				if (a[i][j] == match[index]) {
					index++;
					break;
				}
			}
		}
		
		cout << (index == 4 ? "YES" : "NO") << endl;
	}
}