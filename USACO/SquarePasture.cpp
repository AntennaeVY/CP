#include<bits/stdc++.h>
using namespace std;

struct Rectangle {
	int x1, y1, x2, y2;
};

int main() {
	ifstream fin("square.in");
	ofstream fout("square.out");
	
	Rectangle r1, r2;
	
	fin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
	fin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
	
	int distX = 0, distY = 0;
	
	distX = max(r1.x2, r2.x2) - min(r1.x1, r2.x1);
	distY = max(r1.y2, r2.y2) - min(r1.y1, r2.y1);
	
	fout << 1LL * max(distX, distY) * max(distX, distY) << endl;
}