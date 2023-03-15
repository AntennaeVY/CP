#include<bits/stdc++.h>
using namespace std;

int sum_of_digits(int x) {
	int result = 0;
	
	while(x) {
		result += x % 10;
		x /= 10; 
	}
	
	return result;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, q;
		cin >> n >> q;
		
		vector<int> a(n);
		set<int> idx;
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
			idx.insert(i);
		}
		
		map<int, int> update_cnt;
		
		while(q--) {
			int op, l, r;
			cin >> op >> l;
			
			l--;
			
			if (op == 2) {
				cout << a[l] << endl;
				continue;
			}		
			
			cin >> r;
			r--;	
			
			auto i = idx.lower_bound(l);
			
			for(; i!=idx.end() && *i<=r; i = idx.lower_bound(l)) {
				update_cnt[*i]++;
				a[*i] = sum_of_digits(a[*i]);
			
				l = *i + 1;
				
				if (update_cnt[*i] >= 3 || a[*i] < 10){
					idx.erase(*i);
				}
			}
		}
	}
}