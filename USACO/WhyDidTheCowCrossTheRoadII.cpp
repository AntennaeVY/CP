#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("maxcross.in");
	ofstream fout("maxcross.out");
	
	int N, K, B;
	fin >> N >> K >> B;
	
	vector<int> signals(N, 1), ps(N+1, 0);
	
	for(int i=0; i < B; i++) {
		int x; 
		fin >> x;
		
		signals[x-1] = 0;
	}
	
	for(int i=0; i < N; i++) {
		ps[i+1] = ps[i] + signals[i];
	}
	
	int ans = B;	
	
	for(int i=K; i <= N; i++) {		
		ans = min(K - (ps[i] - ps[i-K]), ans); 
	}
	
	fout << ans << endl;
}