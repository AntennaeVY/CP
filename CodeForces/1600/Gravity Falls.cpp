#include<bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int max_k = 0;
		
		vector<deque<int>> v(n);
		for(int i=0; i < n; i++) {
			int k;
			cin >> k;
			
			max_k = max(max_k, k);
			
			for(int j=0; j < k; j++) {
				int x;
				cin >> x;
				
				v[i].push_back(x);
			}
		}
		
		sort(v.begin(), v.end(), [](auto &a, auto &b){
			return a.size() > b.size();
		});
		
		vector<int> ans;
		
		while(ans.size() < max_k) {
			auto vi = *min_element(v.begin(), v.end());
			int sz = vi.size();
		
			for(auto &x : vi)
				ans.push_back(x);
			
			while(!v.empty() && v.back().size() <= sz)
				v.pop_back();
				
			for(int i=0; i < v.size(); i++) {
				for(int j=0; j < sz; j++) {
					v[i].pop_front();
				}
			}
		}
		
		for(auto &ansi : ans)
			cout << ansi << " ";
		cout << "\n";
	}
}