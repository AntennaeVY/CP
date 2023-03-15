#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("bcount.in");
	ofstream fout("bcount.out");
	
	int N, Q;
	fin >> N >> Q;
	
	vector<int> holsteins(N+1, 0), guernseys(N+1, 0), jerseys(N+1, 0);
	
	for(int i=1; i <= N; i++) {
		int id;
		fin >> id;
		
		if (id == 1)
			holsteins[i]++;
		else if (id == 2)
			guernseys[i]++;
		else
			jerseys[i]++;
	}
	
	for(int i=1; i <= N; i++) {
		holsteins[i] += holsteins[i-1];
		guernseys[i] += guernseys[i-1];
		jerseys[i] += jerseys[i-1];
	}
	
	while(Q--) {
		int a, b;
		fin >> a >> b;
		
		fout << holsteins[b] - holsteins[a-1] << " ";
		fout << guernseys[b] - guernseys[a-1] << " ";
		fout << jerseys[b] - jerseys[a-1] << endl;
 	}
}