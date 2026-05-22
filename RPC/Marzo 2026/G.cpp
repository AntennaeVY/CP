#include<bits/stdc++.h>
using namespace std;

int parse_to_sec(string &s) {
	int h = stoi(s.substr(0, 2));
	int m = stoi(s.substr(3, 2));
	int ss = stoi(s.substr(6, 2));
	
	return h*3600 + m*60 + ss;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n), d(m);
	
	for(int i=0; i < n; i++) {
		string s;
		cin >> s;
		
		a[i] = parse_to_sec(s);
	}
	
	for(int i=0; i < m; i++) {
		string s;
		cin >> s;
		
		d[i] = parse_to_sec(s);
	}
	
	int s;
	cin >> s;
	
	int ans = 1e9;
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			if (a[i] >= d[j])
				continue;
				
			// cout << i << " " << j << endl;
			// cout << a[i] << " " <<d[j] << endl;
				
			if (d[j] - a[i] >= s)
				ans = min(ans, d[j] - a[i]);
		}
	}
	
	if (ans != 1e9)
		cout << ans << "\n";
	else
		cout << -1 << "\n";
}