#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	map<int, int> cnt;
	vector<int> a(n), z(n);
	
	bool ok = true;
	
	for(int i=0; i < n; i++) {
		cin >> a[i];
		
		z[i] = i;
		cnt[a[i]]++;
		
		if (cnt[a[i]] > k)
			ok = false;
	}
	
	if (!ok) {
		cout << "NO" << endl;
		return 0;
	}
	
	sort(z.begin(), z.end(), [&](int i, int j){
		return a[i] < a[j];
	});
	
	int c = 0;
	for(int i=0; i < n; i++) {
		a[z[i]] = c+1;
		c = (c+1)%k;
	}
	
	cout << "YES" << endl;
	for(int ci : a)
		cout << ci << " ";
}