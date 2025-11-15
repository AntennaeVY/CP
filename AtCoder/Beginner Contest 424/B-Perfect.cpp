#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> cnt(n), ans;
	for(int i=0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		
		cnt[--a] += 1;
		
		if (cnt[a] == m)
			ans.push_back(a + 1);
	}

	for(auto &ansi : ans)
		cout << ansi << " ";
}