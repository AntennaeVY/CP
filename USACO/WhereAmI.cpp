#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("whereami.in");
	ofstream fout("whereami.out");
	
	int n;
	string s;
	
	fin >> n >> s;

	map<string, int> freq;
	for(int i=1; i <= n; i++) {
		bool ok = true;
		
		for(int l=0; l <= n-i; l++) {
			string curr = s.substr(l, i);
			
			freq[curr]++;
			if (freq[curr] > 1){
				ok = false;
				break;
			}
		}
		
		if (ok) {
			fout << i << endl;
			return 0;
		}
	}
}