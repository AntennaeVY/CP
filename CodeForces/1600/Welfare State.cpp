#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int q;
	cin >> q;
	
	vector<int> last_receipt_index(n, -1), suffix(q+1, 0);
	
	for(int i=0; i < q; i++) {
		int t;
		cin >> t;
		
		if (t == 1) {
			int p, x;
			cin >> p >> x;
			
			a[p-1] = x;
			last_receipt_index[p-1] = i;
		} else {
			int x;
			cin >> x;
			
			suffix[i] = x;
		}
	}

	for(int i=q-1; i >= 0; i--) {
		suffix[i] = max(suffix[i], suffix[i+1]);
	}
	
	for(int i=0; i < n; i++) {
		cout << max(a[i], suffix[last_receipt_index[i] + 1]) << " ";
	}
	
	cout << endl;
}