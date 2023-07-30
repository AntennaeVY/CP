#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n), z(n);
	set<int> s;
	
	for(int i=0; i < n; i++) {
		cin >> a[i];
		z[i] = i;
		
		s.insert(i);
	}

	sort(z.begin(), z.end(), [&](int i, int j){
		return a[i] > a[j];
	});
	
	vector<int> ans(n, 0);
	
	int turn = 0;
	
	for(int i=0; i < n; i++) {
		if (ans[z[i]])
			continue;
			
		ans[z[i]] = turn+1;
		
		vector<int> curr;
		
		int cnt = 0;	
		for(auto j=prev(s.find(z[i])); j != prev(s.begin()) && cnt < k; j--, cnt++) {
			curr.push_back(*j);
		}
		
		cnt = 0;
		for(auto j=next(s.find(z[i])); j != s.end() && cnt < k; j++, cnt++) {				
			curr.push_back(*j);
		}
		
		for(int x : curr) {
			ans[x] = turn+1;
			s.erase(x);
		}
		
		s.erase(z[i]);	
		
		turn = 1-turn;
	}
	
	for(int i=0; i < n; i++) {
		cout << ans[i];
	}
	
	cout << "\n";
}