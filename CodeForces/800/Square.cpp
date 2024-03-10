#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		vector<pair<int,int>> a(4);
		
		for(int i=0; i < 4; i++) {
			int x, y;
			cin >> x >> y;
			
			a[i] = {x, y};
		}
		
		sort(a.begin(), a.end());
		
		int b = abs(a[1].second - a[0].second);
		
		cout << b * b << endl;
	}
}