#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	int last = 0;
	
	for(int i=1; i <= k; i++) {
		if (i*n + n-1 <= k)
			last = i;
	}
	
	cout << last << endl;
}