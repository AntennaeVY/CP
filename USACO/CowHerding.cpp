#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	
	int N;
	cin >> N;
	
	vector<int> A(N);
	for(auto &Ai : A) cin >> Ai;
	
	sort(A.begin(), A.end());
	
	int maxAns = max(A[N-1] - A[1] - (N-2), A[N-2] - A[0] - (N-2));
	int minAns = 2;
	
	if (!(A[N-1] - A[1] == N-2 && A[1] - A[0] > 2 || A[N-2] - A[0] == N-2 && A[N-1] - A[N-2] > 2)) {
		int r=0;
		minAns = 1e9;
		
		for(int l=0; l < N; l++) {
			while(r < N-1 && A[r+1] - A[l] < N)
				r++;
				
			minAns = min(minAns, N - (r-l+1));
		}
	}
	
	cout << minAns << endl;
	cout << maxAns << endl;
}