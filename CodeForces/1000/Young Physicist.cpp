#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int sumx = 0, sumy = 0, sumz = 0;
	
	for(int i=0; i < n; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		
		sumx += x;
		sumy += y;
		sumz += z;
	}
	
	cout << (sumx == 0 && sumy == 0 && sumz == 0 ? "YES" : "NO") << endl;
}