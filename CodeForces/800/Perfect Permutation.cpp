#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	if (n%2 == 1) {
		cout << -1 << endl;
		return 0;
	}
	
	int a = 1, b = 1;
	
	for(int i=0; i < n; i++) {
		if (i % 2)
			cout << 2*(a++) - 1 << " ";
		else
			cout << 2*(b++) << " ";
	}
	
	cout << endl;
}