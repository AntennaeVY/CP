#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, x;
	cin >> n >> x;
	
	map<int, vector<int>> m;
	vector<int> a(n);
	for(int i=0; i < n; i++) {
		cin >> a[i];
		m[a[i]].push_back(i);
	}

	if (n < 3) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	
	for(int i=0; i < n; i++) {
		for(int j=i+1; j < n; j++) {
			int need = x - (a[i] + a[j]);
			
			if (m.find(need) == m.end())
				continue;
			
			if (a[i] == a[j] && a[i] == need && m[need].size() < 3)
				continue;
				
			if ((a[i] == need || a[j] == need) && m[need].size() < 2)
				continue;
	
			cout << i+1 << " " << j+1 << " " << m[need].back() + 1;
			return 0;
		}
	}

	
	cout << "IMPOSSIBLE" << endl;
}