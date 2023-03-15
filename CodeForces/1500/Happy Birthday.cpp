#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		vector<pair<int, char>> c(10);
		for(int i=0; i < 10; i++) {
			int x;
			cin >> x;
			
			c[i] = {x, (char)(48+i)};
		}
		
		sort(c.begin(), c.end());
		
		auto min1 = c[0], min2 = c[1];
		
		if (min1.second == '0' && min1.first < min2.first) {
			cout << "1" + string(min1.first + 1, '0') << endl;
		} else if (min1.second == '0'){
			cout << string(min2.first + 1, min2.second) << endl;	
		} else {
			cout << string(min1.first + 1, min1.second) << endl;
		}
	}
}