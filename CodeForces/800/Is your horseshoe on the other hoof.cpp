#include<bits/stdc++.h>
using namespace std;

int main() {
	set<int> s;
	int ans = 0;
	
	for(int i=0; i < 4; i++) {
		int x;
		cin >> x;
		
		if (s.count(x))
			ans++;
			
		s.insert(x);
	}
	
	cout << ans << endl;
}