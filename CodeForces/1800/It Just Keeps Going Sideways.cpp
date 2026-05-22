#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ordered_set_pair tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int MAX_AI = *max_element(a.begin(), a.end());
		
		vector<vector<int>> m(MAX_AI + 1);
		for(int i=0; i < n; i++) {
			m[a[i]].push_back(i);
		}
		
		ordered_set s;
		
		vector<long long> cnt(MAX_AI + 2);
		for(int x=MAX_AI; x >= 1; x--) {
			cnt[x] = cnt[x+1];
			int size = m[x].size();
			
			for(int i=size-1; i >= 0; i--) {
				int gte_p = s.order_of_key(m[x][i]);
				int gte_s = s.size() - gte_p;
				
				cnt[x] += n-1 - m[x][i] - gte_p - gte_s;
				
				s.insert(m[x][i]);
			}
		}
		
		long long sum = accumulate(cnt.begin(), cnt.end(), 0LL);
		long long ans = sum;
		
		ordered_set_pair pf, sf;
		for(int i=0; i < n; i++)
			pf.insert({a[i], n-i});
			
		for(int i=n-1; i >= 0; i--) {
			pf.erase(pf.find({a[i], n-i}));
			
			long long gte_p = pf.size() - pf.order_of_key({a[i], n-i});
			long long gte_s = sf.size() - sf.order_of_key({a[i], i});
			
 			ans = max(ans, sum - (n-i-1 - gte_s) + gte_p);
			
			sf.insert({a[i], i});
		}
		
		cout << ans << endl;
	}
}