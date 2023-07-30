#include<bits/stdc++.h>
using namespace std;

int getDivCount(int x) {
	int count = 0;
	while(x%2 == 0) {
		x /= 2;
		count++;
	}
	
	return count;
}

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		long long current = 0, auxiliar = 0;
		vector<int> a(n), aux;
		for(int i=0; i < n; i++) {
			cin >> a[i];
			
			current += getDivCount(a[i]);
			int cnt = getDivCount(i+1);
			auxiliar += cnt;
			
			aux.push_back(cnt);
		}
	
		if (current >= n) {
			cout << 0 << endl;
			continue;
		}		
		
		if (current + auxiliar < n) {
			cout << -1 << endl;
			continue;
		}
		
		int ans = 0;
		sort(aux.rbegin(), aux.rend());
		
		for(auto gives : aux) {
			ans++;
			
			if (current + gives >= n)
				break;
			
			current += gives;
		}
		
		cout << ans << endl;
	}
}