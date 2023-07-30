#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int, int> m;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai, m[ai]++;
		
		if (m.size() == 1) {
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
		
		int root, cnt = 1e9;
		
		for(auto &[i, c] : m) {
			if (c < cnt)
				cnt = c, root = i;
		}
		
		for(int i=0; i < n; i++) {
			if (a[i] != root)
				continue;
				
			root = i;
			break;
		}
		
		set<int> s;
		vector<int> children;
		
		for(int i=0; i < n; i++) {
			if (a[i] != a[root]) {
				cout << root + 1 << " " << i + 1 << endl;
				children.push_back(i+1);
			} else if (i != root){
				s.insert(i+1);
			}
		}
		
		for(int i=0; i < children.size(); i++) {
			if (s.empty())
				break;
				
			cout << children[i] << " " << *s.begin() << endl;
			s.erase(s.begin());
		}
	}
}