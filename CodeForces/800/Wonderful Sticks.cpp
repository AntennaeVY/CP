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
		
		string s;
		cin >> s;
		
		int l=1, r=n;
		
		stack<int> v;
		
		for(int i=n-2; i >= 0; i--) {
			if (s[i] == '>')
				v.push(r--);
			else
				v.push(l++);
		}
		
		v.push(l);
		
		while(!v.empty()) {
			cout << v.top() << " ";
			v.pop();
		}
		
		cout << "\n";
	}
}