#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k, z;
		cin >> n >> k >> z;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> prefix(k+1, 0);
		prefix[0] = a[0];
		
		for(int i=1; i <= k; i++) {
			prefix[i] += prefix[i-1] + a[i];
		}
		
		int score = prefix[k];
		
		for(int i=0; i <= k; i++) {
			for(int j=1; j <= z && k - i - 2*j >= 0; j++) {
				if (i > 0)
					score = max(score, (a[i-1] + a[i]) * j + prefix[k-2*j]);
			
				if (i < n-1)
					score = max(score, (a[i+1] + a[i]) * j + prefix[k-2*j]);
			}
		}
		
		cout << score << endl;
	}
}