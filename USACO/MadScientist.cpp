#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("breedflip.in");
	ofstream fout("breedflip.out");
	
	int n;
	string a, b;
	
	fin >> n >> a >> b;
	
	int ans = 0, amt = 0;
	
	for(int i=0; i < n; i++) {
		if (a[i] != b[i])
			amt = 1;
		else
			ans += amt, amt = 0;
	}
	
	ans += amt;
	
	fout << ans;
}