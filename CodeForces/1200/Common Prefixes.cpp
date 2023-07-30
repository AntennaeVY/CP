#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		string s(50, 'a');
		int letter = 1;
		
		for(int i=0; i < n; i++) {
			cout << s << endl;
			
			if (a[i] != 50)
				s[a[i]] ^= 'a' ^ 'b';
		}
		
		cout << s << endl;
	}
}