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
		
		int x = 0, y = 0;
		
		for(int i=0; i < n; i++) {
			if (i % 4 == 1 || i % 4 == 2)
				x++;
			else
				y++;
		}
		
		if (x&1 || y&1)
			cout << "Alice\n";
		else
			cout << "Bob\n";
	}
}