#include<bits/stdc++.h>
using namespace std;

int main() {
	
	vector<int> x(3), y(3);
	for(int i=0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	
	int A2 = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
	int B2 = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
	int C2 = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
	
	bool good = false;
	
	if (A2 == B2 + C2 || B2 == A2 + C2 || C2 == A2 + B2)
		good = true;
		
	cout << (good ? "Yes" : "No") << endl;
}