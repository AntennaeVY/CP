#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	string s, t;
	cin >> s >> t;
	
	string test = "abc";

	do {
		string c1 = "", c2 = test + test;
		
		for(int i=0; i < 3; i++) {
			c1 += test[i];
			c1 += test[i];
		}
		
		bool ok1 = true, ok2 = true;
		
		for(int i=1; i < 6; i++) {
			string x = "", y = "";
			x += c1[i-1]; y += c2[i-1];
			x += c1[i]; y += c2[i];
			
			ok1 &= (x != s && x != t);
			ok2 &= (y != s && y != t);
		}
		
		if (ok1) {
			cout << "YES" << endl;
			
			for(int i=0; i < 3; i++) {
				for(int j=0; j < n; j++) {
					cout << test[i];
				}
			}
			
			break;
		} else if (ok2) {
			cout << "YES" << endl;
			
			for(int i=0; i < n; i++) {
				cout << test;
			}
			
			break;
		}
		
	} while(next_permutation(test.begin(), test.end()));
}