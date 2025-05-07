#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	stack<int> s;
	
	int q;
	cin >> q;
	
	while(q--) {
		int t;
		cin >> t;
		
		if (t == 1) {
			int x;
			cin >> x;
			
			s.push(x);
		} else {
			if (!s.empty()) {
			cout << s.top() << endl;
			
			s.pop();
			} else {
				cout << 0 << endl;
			}
		}
	}
}