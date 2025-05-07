#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	vector<int> v;
	
	int cnt = 0;
	
	for(int i=0; i < s.size(); i++) {
		if (s[i] == '|') {
			v.push_back(cnt);
			cnt = 0;
		} else {
			cnt += 1;
		}
	}
	
	for(int i=1; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	
	cout << endl;
}