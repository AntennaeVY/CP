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
		
		string s1;
		cin >> s1;
		
		int m;
		cin >> m;
		
		string s2;
		cin >> s2;
		
		string x;
		cin >> x;
		
		deque<char> dq;
		for(int i=0; i < n; i++) {
			dq.push_back(s1[i]);
		}
		
		for(int i=0; i < m; i++) {
			if (x[i] == 'D')
				dq.push_back(s2[i]);
			else
				dq.push_front(s2[i]);
		}
		
		for(auto &di : dq)
			cout << di;
		cout << "\n";
	}
}