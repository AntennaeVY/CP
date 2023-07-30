#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	
	map<int, int> cnt;
	for(int i=0; i < n; i++) {
		int ai;
		cin >> ai;
		
		cnt[ai]++;
	}
	
	bool ok = true;
	
	for(int i=1; i < x; i++) {
		if (cnt[i] % (i+1))
			ok = false;
		
		cnt[i+1] += cnt[i] / (i+1);
	}
	
	cout << (ok ? "YES" : "NO") << endl;
}