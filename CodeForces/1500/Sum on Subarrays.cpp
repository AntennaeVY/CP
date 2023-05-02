#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n, -1);
		
		function<void(int, int)> construct;
		construct = [&](int n_i, int k_i){
			if (k_i <= 0)
				return;
			
			if (k_i < n_i) {
				a[k_i - 1] = 100, a[k_i] = -200;
				return;
			}
			
			a[n_i - 1] = 1000;
			construct(n_i - 1, k_i - n_i);
		};
		
		construct(n, k);
		
		for(auto a_i : a) {
			cout << a_i << " ";
		}
		
		cout << endl;
	}
}