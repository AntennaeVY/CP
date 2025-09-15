#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int x = stoi(s);
		
		int rt = sqrt(x);
		
		if (rt * rt != x) {
			cout << -1 << "\n";
			continue;
		}
		
		if (x == 0) {
			cout << "0 0" << endl;
			continue;
		}
		
		cout << 1 << " " << rt - 1 << endl;
	}
}