#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<string> v = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
	
	char d;
	cin >> d;
	
	string s;
	cin >> s;
	
	string ans = "";
	
	for(char c : s) {
		for(int i=0; i < 3; i++) {
			for(int j=0; j < v[i].size(); j++) {
				if (d == 'L' && j > 0 && v[i][j-1] == c)
					ans += v[i][j];
				else if (d == 'R' && j < v[i].size() - 1 && v[i][j+1] == c)
					ans += v[i][j];
			}
		}
	}
	
	cout << ans << endl;
}