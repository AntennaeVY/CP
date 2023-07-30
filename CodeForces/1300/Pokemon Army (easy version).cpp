#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,q;
		cin >> n >> q;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		a.push_back(0);
		vector<int> subsequence;
		long long maxSum = 0;
		bool increase = true;
		
		for(int i=1; i <= n; i++) {			
			if (a[i] < a[i-1] && increase) {
				subsequence.push_back(a[i-1]);
				increase = false;
			} else if (a[i] > a[i-1] && !increase) {
				subsequence.push_back(a[i-1]);
				increase = true;
			}
		}
		
		for(int i=0; i < subsequence.size(); i++) {
			if (i%2 == 0)
				maxSum += subsequence[i];
			else
				maxSum -= subsequence[i];
		}
		
		cout << maxSum << endl;
	}
}