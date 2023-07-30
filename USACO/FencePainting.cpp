#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d;
	ifstream fin("paint.in");
	ofstream fout("paint.out");
	
	fin >> a >> b >> c >> d;
	
	fout << (b-a) + (d-c) - max(0, min(b,d) - max(a,c)) << endl;
		
}