#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s, colors = "BGR";
	cin >> s;
	
	int ans = n;
	string t = "";
	
	do {
		int current = 0;
		string x = s;
		
		for(int i=0; i < n; i++) {
			if (s[i] != colors[i%3])
				current++, x[i] = colors[i%3];
		}
		
		if (current < ans) {
			ans = current;
			t = x;
		}		
	} while(next_permutation(colors.begin(), colors.end()));
	
	cout << ans << endl;
	cout << t << endl;
}