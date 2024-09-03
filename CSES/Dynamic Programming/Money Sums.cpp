#include<bits/stdc++.h>
using namespace std;

constexpr int MAX = 1e5 + 5;
bool dp[MAX];

int main() {
	int n;
	cin >> n;
	
	vector<int> x(n);
	for(auto &xi : x) cin >> xi;
	
	sort(x.rbegin(), x.rend());
	
	for(int i=0; i < MAX; i++)
		dp[i] = false;
	
	dp[0] = true;
	
	for(int i=0; i < n; i++) {
		for(int k=MAX-1; k-x[i] >= 0; k--) {
			dp[k] |= dp[k-x[i]]; 
		}
	}
	
	vector<int> v;
	
	for(int i=1; i < MAX; i++) {
		if (dp[i])
			v.push_back(i);	
	}
	
	cout << v.size() << endl;
	for(auto &vi : v) cout << vi << " ";
	cout << endl;
}