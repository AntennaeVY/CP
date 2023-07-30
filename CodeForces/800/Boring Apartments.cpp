#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int x;
		cin >> x;
		
		int cnt = 10*(x%10 - 1);
		int sz = to_string(x).size();
		
		cnt += sz*(sz+1)/2;
		
		cout << cnt << endl;
	}
}