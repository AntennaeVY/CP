#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	int c = 0;
	
	vector<pair<int,int>> v = {{x1, y1}, {x2, y2}};
	
	for(auto &[x, y] : v) {
		if (x == 0 && y == 0)
			c++;
			
		if (x == 0 && y == 2024)
			c++;
			
		if (x == 2024 && y == 0)
			c++;
			
		if (x == 2024 && y == 2024)
			c++;
	}
	
	cout << 2 - c << endl;
}