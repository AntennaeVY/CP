#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> a(10);
	for(auto &ai : a) cin >> ai;
	
	int x, y;
	cin >> x >> y;
	
	int z = 0;
	
	for(int i=0; i < 10; i+=2) {
		z += a[i] * a[i+1];
	}
	
	z /= 5;
	
	cout << (x * z) / y << "\n"; 
}