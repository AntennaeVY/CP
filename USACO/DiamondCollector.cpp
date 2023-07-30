#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int N, K;
	cin >> N >> K;
	
	vector<int> a(N);
	for(auto &ai : a) cin >> ai;
	
	sort(a.begin(), a.end());
	
	vector<int> mx(N);
	int best = 0, ans = 0, l = 0;
	
	for(int r=0; r < N; r++) {
		while(a[r] - a[l] > K) {
			best = max(best, mx[l]);
			l++;
		}
		
		mx[r] = r-l+1;
		ans = max(ans, mx[r] + best);
	}
	
	cout << ans << endl;
}