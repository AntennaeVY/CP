#include<bits/stdc++.h>
using namespace std;

long long ans = LLONG_MAX;

void generate_subset(int from, int to, vector<int>& subset, vector<int>&p) {
	if (from == to) {
		long long sum = 0, total = 0;
		
		for(int i=0; i < subset.size(); i++) {
			sum += p[subset[i]];
		}
		
		for(int i=0; i < to; i++) {
			total += p[i];
		}
		
		ans = min(ans, abs(total-2*sum));
		
		return;	
	}
	
	generate_subset(from+1, to, subset, p);
	subset.push_back(from);
	generate_subset(from+1, to, subset, p);
	subset.pop_back();
}

int main() {
	int n;
	cin >> n;
	
	vector<int> p(n);
	for(auto &pi:p) cin >> pi;
	
	vector<int> subset;
	
	generate_subset(0, n, subset, p);
	
	cout << ans << endl;
}