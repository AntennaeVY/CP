#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		stack<int> s;
		
		for(int i=0; i < n; i++) {
			char x;
			cin >> x;
			
			if (x == 'Q')
				s.push(x);
			else if (!s.empty())
				s.pop();
		}
		
		cout << (!s.empty() ? "No" : "Yes") << endl;
	}
}