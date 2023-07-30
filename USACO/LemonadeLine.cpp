#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<int> w(n);
	for(auto &wi : w) cin >> wi;
	
	sort(w.rbegin(), w.rend());
	
	int cnt = 0;
	
	for(int i=0; i < n; i++) {
		if (w[i] >= cnt)
			cnt++;
	}
	
	cout << cnt << endl;
}