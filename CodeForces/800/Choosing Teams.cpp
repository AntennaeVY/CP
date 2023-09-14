#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	int cnt = 0;
	
	for(int i=0; i < n; i++) {
		int y;
		cin >> y;
		
		if (y <= 5-k)
			cnt++;
	}
	
	cout << cnt / 3 << endl;
}