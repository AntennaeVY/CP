#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	double sum = 0;
	for(int i=0; i < n; i++) {
		int x;
		cin >> x;
		
		sum += x;
	}
	
	cout << sum / n << endl;
}