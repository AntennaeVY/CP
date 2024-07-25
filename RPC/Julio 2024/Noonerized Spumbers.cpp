#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<string> v(3);
	char op, eq;
	
	cin >> v[0] >> op >> v[1] >> eq >> v[2];
	
	string ans = "";
	
	for(int i=0; i < 3; i++) {
		for(int j=i+1; j < 3; j++) {
			
			for(int l=1; l < v[i].size(); l++) {
				for(int r=1; r < v[j].size(); r++) {
					string p1 = v[i].substr(0, l);
					string s1 = v[i].substr(l);
					
					string p2 = v[j].substr(0, r);
					string s2 = v[j].substr(r);
					
					string a = v[i];
					string b = v[j];
					
					v[i] = p2 + s1;
					v[j] = p1 + s2;
					
					long long x = stol(v[0]);
					long long y = stol(v[1]);
					long long z = stol(v[2]);
					
					if (
						op == '+' && x + y == z || 
					    op == '*' && x * y == z
					)
						ans = v[0] + " " + op + " " + v[1] + " = " + v[2];
					
					v[i] = a, v[j] = b;
				}
			}
			
		}
	}
	
	cout << ans << endl;
}