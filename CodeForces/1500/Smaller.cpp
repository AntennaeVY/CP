#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int q;
		cin >> q;
		
		unordered_map<char,long long> s = {{'a', 1}}, t = {{'a', 1}};
				
		for(int i=0; i < q; i++) {
			int d, k;
			cin >> d >> k;
			
			string x;
			cin >> x;
			
			for (char ch : x) {
				if (d == 1)
					s[ch] += k;
				else 
					t[ch] += k;
			}
			
			if (t.size() > 1 || t.size() == 1 && s.size() == 1 && t['a'] > s['a'])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}