#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("cowsignal.in");
	ofstream fout("cowsignal.out");
	
	int m, n, k;
	fin >> m >> n >> k;
	
	for(int i=0; i < m; i++) {
		string line = "";
		
		for(int j=0; j < n; j++) {
			char ch;
			fin >> ch;
			
			line += string(k, ch);
		}
		
		for(int j=0; j < k; j++) {
			fout << line << endl;
		}
	}
}