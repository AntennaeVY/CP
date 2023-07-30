#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int p = 1;
		vector<int> ans;
		
		while(n != 0) {
			if (n%10)
				ans.push_back((n%10) * p);
				
			n /= 10;
			p *= 10;
		}
		
		cout << ans.size() << endl;
		for(int i : ans) 
			cout << i << " ";
			
		cout << endl;
	}
}