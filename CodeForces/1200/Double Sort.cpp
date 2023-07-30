#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai:a) cin >> ai;
		for(auto &bi:b) cin >> bi;
		
		vector<int> indexes(n);
		for(int i=0; i < n; i++) indexes[i] = i;
		
		sort(indexes.begin(), indexes.end(), [a,b](const int &i, const int &j) {
		if (a[i] == a[j])
			return b[i] < b[j];
		else
			return a[i] < a[j];
		});
		
		bool sorted = true;
		
		for(int i=0; i < n-1; i++) {
			if (a[indexes[i]] > a[indexes[i+1]] || b[indexes[i]] > b[indexes[i+1]]) {
				sorted = false;
				break;
			}
		}
		
		if (!sorted) {
			cout << -1 << endl;
			continue;
		}
		
		vector<pair<int,int>> ans;
		
		for(int i=0; i < n-1; i++) {
			for(int j=0; j < n-1; j++) {
				if (a[j] > a[j+1] || b[j] > b[j+1]) {
					swap(a[j], a[j+1]);
					swap(b[j], b[j+1]);
					ans.push_back({j+1, j+2});
				}
			}
		}
		
		cout << ans.size() << endl;
		
		for(auto x:ans) {
			cout << x.first << " " << x.second << endl;
		}

	}
}