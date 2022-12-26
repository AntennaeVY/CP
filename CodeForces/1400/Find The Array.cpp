#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		long long odd_sum = 0, even_sum = 0;
		
		for(int i=1; i <= n; i++) {
			if (i%2 == 0)
				even_sum += a[i-1];
			else
				odd_sum += a[i-1];
		}
		
		if (even_sum < (even_sum + odd_sum)/2) {
			for(int i=1; i <= n; i++) {
				if (i%2)
					cout << a[i-1] << " ";
				else
					cout << 1 << " ";
			}
		} else {
			for(int i=1; i <= n; i++) {
				if (i%2 == 0)
					cout << a[i-1] << " ";
				else
					cout << 1 << " ";
			}
		}
		
		cout << endl;
	}
}