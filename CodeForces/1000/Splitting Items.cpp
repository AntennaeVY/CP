#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
	 int n, k;
	 cin >> n >> k;
	 
	 vector<int> a(n);
	 for(auto &ai : a) cin >> ai;
	 
	 sort(a.rbegin(), a.rend());
	 
	 long long bob = 0;
	 
	 for(int i=1; i < n; i+=2) {
	 	int diff = (a[i-1] - a[i]);
	 	
	 	a[i] += min(diff, k), k -= min(diff, k);
	 	bob += a[i];
	 }
	 
	long long sum = accumulate(a.begin(), a.end(), 0LL);
	
	cout << (sum - 2*bob) << endl;
  }
}