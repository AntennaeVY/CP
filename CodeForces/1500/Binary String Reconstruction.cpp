#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n0, n1, n2;
		cin >> n0 >> n1 >> n2;
		
		string ans = "";
		
		for(int i=0; i < n0; i++)
			ans += "0";
			
		if (n0 != 0 || n1 != 0)
			ans += "0";
			
		for(int i=0; i < n2; i++)
			ans += "1";
			
		if (n1 == 0 && n2 != 0)
			ans += "1";
			
		for(int i=0; i < n1; i++)
			ans += to_string(1-(i%2));
			
		cout << ans << endl;
	}
}