#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		long long neg = 0, pos = 0;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			if (x < 0)
				neg += x;
				
			if (x > 0)
				pos += x;
		}
		
		cout << max(pos - abs(neg), abs(neg) - pos) << endl;
	}
}