#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int i=1, cnt = 0;
	
	while(cnt < n) {
		cnt += 1LL*i*(i+1)/2;
		
		if (cnt > n) 
			break;
		
		i++;
	}
	
	cout << i - 1 << endl;
}