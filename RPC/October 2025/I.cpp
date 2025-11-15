#include<bits/stdc++.h>
using namespace std;

int symmetric_difference_size(set<int> &s1, set<int> &s2) {
	int cnt = 0;
	
	for(auto &x : s1)
		if (!s2.count(x))
			cnt++;
			
	for(auto &x : s2)
		if (!s1.count(x))
			cnt++;
	
	return cnt;
}

int get_min_changes(set<int> &s1, set<int> &s2, int x) {
	// deselect all + select what you want
	int d = 1 + s1.size();
	
	// select all + deselect what you dont want
	int s = 1 + (x - s1.size());
	
	// manually select what you want and deselect what you dont want
	int m = symmetric_difference_size(s1, s2);
	
	
	return min({d, s, m});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, s, p, q;
	cin >> n >> m >> s >> p >> q;
	
	int pages = (n + m - 1) / m;
	vector<set<int>> need(pages + 5), preselected(pages + 5);
	
	for(int i=0; i < p; i++) {
		int x;
		cin >> x;
		
		preselected[(x + m - 1) / m].insert(x);
	}
	
	for(int i=0; i < q; i++) {
		int x;
		cin >> x;
		
		need[(x + m - 1) / m].insert(x);
	}
	
	int l = -1, r = -1;
	for(int i=1; i <= pages; i++) {
		if (l == -1) {
			if (symmetric_difference_size(need[i], preselected[i])) {
				l = i;
			}
		}
		
		if (symmetric_difference_size(need[i], preselected[i])) {
			r = i;
		}
	}
	
	if (l == -1 && r == -1) {
		cout << 0 << endl;
		return 0;
	}
	
	l = max(1, l);
	r = min(pages, r);
	
	int ans = 0;
	
	if (l >= s) {
		for(int i=s; i <= r; i++) {
			if (!symmetric_difference_size(need[i], preselected[i]))
				continue;
			
			ans += get_min_changes(need[i], preselected[i], (i == pages ? (n - m*(pages-1)) : m));
		}
		
		ans += r-s;
	} else if (r <= s) {
		for(int i=s; i >= l; i--) {
			if (!symmetric_difference_size(need[i], preselected[i]))
				continue;

			ans += get_min_changes(need[i], preselected[i], (i == pages ? (n - m*(pages-1)) : m));
		}
		
		ans += s-l;
	} else {
		
		if (s-l < r-s) {
			
			for(int i=s; i >= l; i--) {
				if (!symmetric_difference_size(need[i], preselected[i]))
					continue;
					
				ans += get_min_changes(need[i], preselected[i], (i == pages ? (n - m*(pages-1)) : m));
			}
			
			for(int i=s+1; i <= r; i++) {
				if (!symmetric_difference_size(need[i], preselected[i]))
					continue;
					
				ans += get_min_changes(need[i], preselected[i], (i == pages ? (n - m*(pages-1)) : m));
			}
			
			
			ans += (s-l + r-l);
		} else {
				
			for(int i=s; i <= r; i++) {
				if (!symmetric_difference_size(need[i], preselected[i]))
					continue;
					
				ans += get_min_changes(need[i], preselected[i], (i == pages ? (n - m*(pages-1)) : m));
			}
			
			for(int i=s-1; i >= l; i--) {
				if (!symmetric_difference_size(need[i], preselected[i]))
					continue;
					
				ans += get_min_changes(need[i], preselected[i], (i == pages ? (n - m*(pages-1)) : m));
			}
			
			ans += (r-s + r-l);
		}	
	}
	
	cout << ans << "\n";
}