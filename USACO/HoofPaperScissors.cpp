#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("hps.in");
	ofstream fout("hps.out");
	
	int N;
	fin >> N;
	
	vector<int> hoof_wins(N+1,0), paper_wins(N+1,0), scissors_wins(N+1,0);
	
	for(int i=1; i <= N; i++) {
		char played;
		fin >> played;
		
		if (played == 'H') 
			paper_wins[i] += 1;
		else if (played == 'P')
			scissors_wins[i] += 1;
		else
			hoof_wins[i] += 1;
	}
	
	for(int i=1; i <= N; i++) {
		paper_wins[i] += paper_wins[i-1];
		scissors_wins[i] += scissors_wins[i-1];
		hoof_wins[i] += hoof_wins[i-1];
	}
	
	int ans = 0;
	
	for(int i=0; i <= N; i++) {
		ans = max(ans, hoof_wins[i] + paper_wins[N] - paper_wins[i]);
		ans = max(ans, hoof_wins[i] + scissors_wins[N] - scissors_wins[i]);
		
		ans = max(ans, paper_wins[i] + scissors_wins[N] - scissors_wins[i]);
		ans = max(ans, paper_wins[i] + hoof_wins[N] - hoof_wins[i]);
		
		ans = max(ans, scissors_wins[i] + paper_wins[N] - paper_wins[i]);
		ans = max(ans, scissors_wins[i] + hoof_wins[N] - hoof_wins[i]);
	}
	
	fout << ans << endl;
}