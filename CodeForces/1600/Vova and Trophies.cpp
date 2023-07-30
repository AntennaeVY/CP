#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int cnt = 0;
	vector<int> starts(n, 0), ends(n, 0);

	cnt = count(s.begin(), s.end(), 'G');
	
	if (cnt == n) {
		cout << n << endl;
		return 0; 
	}
	
	for(int i=0; i < n; i++) {
		if (s[i] == 'S')
			continue;
			
		ends[i] = ends[max(0, i-1)] + (s[i] == 'G');
	}
	
	for(int i=n-1; i >= 0; i--) {
		if (s[i] == 'S')
			continue;
			
		starts[i] = starts[min(n-1, i+1)] + (s[i] == 'G');
	}
	
	int ans = 0;
	
	for(int i=0; i < n; i++) {
		if (s[i] == 'G')
			continue;
			
		int curr = 0;
		
		if (i > 0) curr += ends[i-1];
		if (i < n-1) curr += starts[i+1];
		
		if (curr < cnt)
			curr++;
			
		ans = max(ans, curr);
	}

	cout << ans << endl;
}