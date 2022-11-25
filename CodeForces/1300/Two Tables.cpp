#include<bits/stdc++.h>
using namespace std;

struct Rectangle {
	int x1,y1,x2,y2;
	
	int getWidth() {
		return x2-x1;
	}
	
	int getHeight() {
		return y2-y1;
	}
};


int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int W, H;
		cin >> W >> H;
		
		Rectangle blue;
		cin >> blue.x1 >> blue.y1 >> blue.x2 >> blue.y2;
		
		int w, h;
		cin >> w >> h;
		
		int ans = 1e8;
		
		if (blue.getWidth() + w <= W) {
			int moveRight = max(0, w-blue.x1);
			int moveLeft = max(0, w-(W-blue.x2));
			
			ans = min(moveRight, moveLeft);
		}
		
		if (blue.getHeight() + h <= H) {
			int moveUp = max(0, h-blue.y1);
			int moveDown = max(0, h-(H-blue.y2));
			
			ans = min(ans, min(moveUp, moveDown));
		}
		
		if (ans != 1e8)
			cout << ans << endl;
		else 
			cout << -1 << endl;
	}
}