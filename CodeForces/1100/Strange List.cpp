#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		long long sum = 0;
		vector<pair<int,int>> a;
		
		for(int i=0; i < n; i++) {
			int num;
			cin >> num;
			a.push_back({num, 1});
			sum += num;
		}
		
		for(int i=0; i < a.size(); i++) {
			if (a[i].first % x) break;
			
			a.push_back({a[i].first/x, x*a[i].second});
	
			sum += 1LL*a[i].first*a[i].second;
		}		
		
		cout << sum << endl;
	}
}