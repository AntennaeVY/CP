#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n), b(n);
	for(int i=0; i < n; i++) {
		cin >> a[i];
		b[i] = i;
	}
	
	sort(b.begin(), b.end(), [&](int i, int j){
		if (a[i] == a[j])
			return i < j;
		else
			return a[i] > a[j];
	});
	
	int m;
	cin >> m;
	
	while(m--) {
		int k, pos;
		cin >> k >> pos;
		
		vector<int> c;
		for(int i=0; i < k; i++) {
			c.push_back(b[i]);
		}
		
		sort(c.begin(), c.end());
		
		cout << a[c[pos-1]] << endl;
	}
}