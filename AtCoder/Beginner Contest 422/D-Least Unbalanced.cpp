#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vector<int> ans = {k};
	
	for(int i=0; i < n; i++) {
		vector<int> v;
		
		for(auto &a : ans) {
			v.push_back(a / 2);
			v.push_back(a - a/2);
		}
		
		ans = v;
	}	
	
	cout << *max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end()) << "\n";
	
	for(auto &ansi : ans)
		cout << ansi << " ";
	cout << "\n";
}