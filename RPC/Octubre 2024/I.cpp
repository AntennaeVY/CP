#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set                            \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>
int main() {
	int n, t;
	cin >> n >> t;
	
	ordered_set s;
	
	while(t--) {
		char c;
		cin >> c;

		int l;
		cin >> l;
		
		if (c == 'R')
			s.insert(l);
			
		if (c == 'A') {
			int r;
			cin >> r;
			
			cout << r-l+1 - (s.order_of_key(r+1) - s.order_of_key(l)) << '\n';
		}
	}
}