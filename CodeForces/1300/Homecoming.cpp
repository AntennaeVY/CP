#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a,b,p;
		cin >> a >> b >> p;
		
		string s;
		cin >> s;
		
		long long sum = 0;
		vector<int> indexes;
		
		string fixed;
		fixed += s[0];
		indexes.push_back(1);
		
		for(int i=1; i < s.size()-1; i++) {
			if (s[i] != s[i-1]) {
				fixed += s[i];
				indexes.push_back(i+1);
			}
		}
		
		vector<pair<long long, int>> calculated_sums = {{0, s.size()}};
		
		for(int i=fixed.size()-1; i >= 0; i--) {
			sum += (fixed[i] == 'A' ? a : b);
			
			calculated_sums.push_back({sum, indexes[i]});
		}
		
		for(int i=calculated_sums.size()-1; i >= 0; i--) {
			if (calculated_sums[i].first <= p) {
				cout << calculated_sums[i].second << endl;
				break;
			}
		}
	}
}