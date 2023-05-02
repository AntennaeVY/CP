#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("stacking.in");
	ofstream fout("stacking.out");
	
	int N, K;
	fin >> N >> K;
	
	vector<int> stacks(N, 0);
	
	while(K--) {
		int A, B;
		fin >> A >> B;
		
		stacks[A-1] += 1;
		
		if (B < N)
			stacks[B] -= 1;
	}	
	
	for(int i=1; i < N; i++) {
		stacks[i] += stacks[i-1];
	}
	
	sort(stacks.begin(), stacks.end());
	fout << stacks[N/2] << endl;
}