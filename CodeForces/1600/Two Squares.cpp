#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> x1(4), y1(4), x2(4), y2(4);
	
	for(int i=0; i < 4; i++) {
		cin >> x1[i] >> y1[i];
	}
	
	for(int i=0; i < 4; i++) {
		cin >> x2[i] >> y2[i];
	}
	
	int l = min(x1[0], x1[2]);
	int r = max(x1[0], x1[2]);
	int d = min(y1[0], y1[2]);
	int u = max(y1[0], y1[2]);
	
	int cx = (x2[0] + x2[2]);
	int cy = (y2[0] + y2[2]);
	
	if (2*l <= cx && cx <= 2*r && 2*d <= cy && cy <= 2*u) {
		cout << "YES" << endl;
		return 0;
	}
	
	for(int i=0; i < 4; i++) {
		if (l <= x2[i] && x2[i] <= r && d <= y2[i] && y2[i] <= u) {
			cout << "YES" << endl;
			return 0;
		}
	}
	
	for(int i=0; i < 4; i++) {
		int x = x1[i], y = y1[i];
		
		x1[i] = x + y;
		y1[i] = x - y;
	}
	
	for(int i=0; i < 4; i++) {
		int x = x2[i], y = y2[i];
		
		x2[i] = x + y;
		y2[i] = x - y;
	}
	
	l = min(x2[0], x2[2]);
	r = max(x2[0], x2[2]);
	d = min(y2[0], y2[2]);
	u = max(y2[0], y2[2]);
	
	for(int i=0; i < 4; i++) {
		if (l <= x1[i] && x1[i] <= r && d <= y1[i] && y1[i] <= u) {
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
}