#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		vector<vector<int>> ans;
		for(auto &ai:a) cin >> ai;
		
		for(int i=0; i < n; i++) {
			int mini = i;
			
			for(int j=i; j < n; j++) {
				if (a[j] < a[mini]) 
					mini = j;
			}
			
			if (mini == i) continue;
			
			vector<int> temp;
			
			for(int j=mini; j < n; j++) {
				temp.push_back(a[j]);
			}
			
			for(int j=i; j < mini; j++) {
				temp.push_back(a[j]);
			}
			
			for(int j=i; j < n; j++) {
				a[j] = temp[j-i];
			}

			ans.push_back({i+1,n, mini-i});
		}
		
		cout << ans.size() << endl;
		
		for(auto x : ans) {
			for (auto y : x) {
				cout << y << " ";
			}
			
			cout << endl;
		}
	}
}