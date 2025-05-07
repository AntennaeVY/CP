#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string a, b;
		cin >> a >> b;
		
		int odd = 0, even = 0;
		
		for(int i=0; i < n; i++) {
			if (i % 2 == 0) 
				even += (a[i] == '0'), odd += (b[i] == '0');
			else
				odd += (a[i] == '0'), even += (b[i] == '0');
		}
		
		if (even >= (n+1)/2 && odd >= n/2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}