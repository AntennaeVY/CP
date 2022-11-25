#include<bits/stdc++.h>
using namespace std;

struct Rectangle {
	int x1,y1,x2,y2;
};

long long intersect(Rectangle a, Rectangle b) {
	int x = max(min(a.x2, b.x2) - max(a.x1, b.x1),0);
	int y = max(min(a.y2, b.y2) - max(a.y1, b.y1),0); 
	
	return 1LL*x*y;
}

long long area(Rectangle a) {
	return 1LL * (a.y2 - a.y1) * (a.x2 - a.x1);
}

int main() {
	Rectangle white, black1, black2;
	
	cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
	cin >> black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
	cin >> black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;

	Rectangle intersection;
	
	intersection.x1 = max(black1.x1, black2.x1);
	intersection.y1 = max(black1.y1, black2.y1);
	intersection.x2 = min(black1.x2, black2.x2);
	intersection.y2 = min(black1.y2, black2.y2);
	
	long long remaining = 0;
	
	if (intersection.x2 - intersection.x1 > 0 && intersection.y2 - intersection.y1 > 0) {
		remaining = intersect(white, intersection);
	}

	if (area(white) - intersect(white, black1) - intersect(white, black2) + remaining > 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}