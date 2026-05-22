#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m;
	cin >> m;
	
	vector<int> a(m);
	for(auto &ai : a) cin >> ai;
	
	array<int, 1000> cnt({});
	for(int i=0; i < m; i++) {
		cnt[a[i]]++;
	}
	
	int l=0, r=1001;
	while(l+1 < r) {
		int x = l + (r-l)/2;
		
		array<int, 1000> cnt2({});
		for(int i=0; i < x; i++) {
			for(int j=0; j < x; j++) {
				cnt2[i+j] += 1;
			}
		}
		
		bool can = true;
		for(int i=0; i < 205; i++) {
			can &= cnt2[i] >= cnt[i];
		}
		
		if (can)
			r = x;
		else
			l = x;
	}
	
	cout << r << "\n";
}