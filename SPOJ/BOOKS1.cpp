#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int m, k;
		cin >> m >> k;
		
		vector<int> a(m);
		for(auto &ai : a) cin >> ai;
		
		long long l = *max_element(a.begin(), a.end()) - 1, r = 1e10, cnt = 0;
		
		while(l + 1 < r) {
			int x = l + (r-l)/2;
			
			long long sum = 0;
			cnt = 1;
			
			for(int i=m-1; i >= 0; i--) {
				if (sum + a[i] > x)
					sum = 0, cnt++;
				
				sum += a[i];
			}
				
			if (cnt <= k)
				r = x;
			else
				l = x;
		}
		
		vector<vector<int>> ans;
		vector<int> curr;
		
		long long sum = 0;
		
		for(int i=m-1; i >= 0; i--) {
			if (sum + a[i] <= r) {
				curr.push_back(a[i]);
				sum += a[i];
			} else {
				reverse(curr.begin(), curr.end());
				ans.push_back(curr);
				
				sum = a[i];
				curr = { a[i] };
			}
		}
		
		reverse(curr.begin(), curr.end());
		ans.push_back(curr);
		
		reverse(ans.begin(), ans.end());
		
		int diff = k - cnt;
		
		for(int i=0; i < ans.size(); i++) {
			for(int j=0; j < ans[i].size(); j++) {
				cout << ans[i][j] << " \n"[i == ans.size() - 1 && j == ans[i].size() - 1];
				
				if (diff > 0 && j < ans[i].size() - 1) {
					cout << "/ ";
					diff--; 
				}
				
			}
			
			if (i < ans.size() - 1)
				cout << "/ ";
		}
	}
} 