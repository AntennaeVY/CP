#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<string> a(n);
	for(auto &ai : a) cin >> ai;
	
	map<int, long long> m;
	
	for(int i=0; i < n; i++) {
		int k = 0;
		
		for(char c : a[i]) {
			k ^= (1 << c - 'a');
		}
		
		m[k]++;
	}
	
	long long ans = 0;
	
	for(auto &[k, cnt] : m) {
		ans += cnt*(cnt-1);
		
		for(int i=0; i < 26; i++) {
			int p = k ^ (1 << i);
			
			if (m.find(p) == m.end())
				continue;
			
			ans += cnt * m[p];
		}
	}
	
	cout << ans / 2 << endl;
}