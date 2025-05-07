#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		cout << "? 1 1" << endl;
		
		int x;
		cin >> x;
		
		if (x == 0) {
			cout << "! 1 1" << endl;
			continue;
		}
		
		if (1 + x <= m) {
			cout << "? 1 " << min(1 + x, m) << endl;
			
			int y;
			cin >> y;
		
			if (y < x) {
				cout << "! " << 1 + y << " " << 1 + x << endl;
				continue;
			}
		}
		
		if (1 + x <= n) {
			cout << "? " << 1 + x << " 1" << endl;
		
			int z;
			cin >> z;
			
			if (z < x) {
				cout << "! " << 1 + x << " " << 1 + z << endl;
				continue;
			}
		}
		
		cout << "! " << 1 + x << " " << 1 + x << endl;
	}
}