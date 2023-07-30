#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("notlast.in");
	ofstream fout("notlast.out");
	
	int n;
	fin >> n;
	
	map<string, int> m;
	
	for(int i=0; i < n; i++) {
		string cow;
		int milk;
		
		fin >> cow >> milk;
		m[cow] += milk;
	}
	
	int mn_m = 1e9;
	string mn_c;
	
	for(auto &[c, mi] : m) {
		if (mi < mn_m)
			mn_m = mi, mn_c = c;
	}	
	
	int curr = 1e9;
	string ans;
	
	for(auto &[c, mi] : m) {
		if (mi > curr || mi == mn_m)
			continue;
			
		curr = mi;
		ans = c;
	}
	
	int cnt1 = 0, cnt2 = 0;
	for(auto &[c, mi] : m) {
		cnt1 += (mi == curr);
		cnt2 += (mi == mn_m);
	}
	
	if (m.size() < 7) {
		fout << (cnt2 == 1 ? mn_c : "Tie") << endl;
	} else {
		fout << (cnt1 == 1 ? ans : "Tie") << endl;
	}
}