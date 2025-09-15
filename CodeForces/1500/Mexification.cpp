#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	// for all repeated a_i => mex of (a)
	// for all non-repeated a_i => min(mex of (a), a_i)
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		long long sum = accumulate(a.begin(), a.end(), 0LL);
		map<int, int> cnt;
		
		for(int i=0; i < n; i++) {
			cnt[a[i]]++;
		}
		
		int mex = 0;
		
		for(int i=0; i <= n; i++) {
			if (cnt[i])
				mex++;
			else
				break;
		}
		
		vector<int> a1(a), a2(a), a3(a);
		long long sum1 = sum, sum2 = sum, sum3 = sum;
		
		while(k--) {
			bool cyclic = true;
			
			sum3 = sum2;
			for(int i=0; i < n; i++) {
				a3[i] = a2[i];
			}
			
			sum2 = sum1;
			for(int i=0; i < n; i++) {
				a2[i] = a1[i];
			}
			
			map<int,int> cnt1;
			sum1 = 0;
			for(int i=0; i < n; i++) {
				if (cnt[a1[i]] > 1)
					a1[i] = mex;
				else
					a1[i] = min(a1[i], mex);
			
				cnt1[a1[i]]++;
				sum1 += a1[i];
			}
			
			cnt = cnt1;
			
			mex = 0;
			for(int i=0; i <= n; i++) {
				if (cnt[i])
					mex++;
				else
					break;
			}
	
			for(int i=0; i < n; i++) {
				cyclic &= (a1[i] == a3[i]);
			}
			
			if (cyclic)
				break;
		}
		
		if (k == -1)
			k++;
		
		if (k % 2 == 0)
			cout << sum1 << "\n";
		else
			cout << sum2 << "\n";
	}
}