#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		int n;
		cin >> n;
		
		vector<int> a(n), ans(n);
		for(auto &ai:a) cin >> ai;
		
		vector<bool> visited(n+1);
		vector<int> index(n+1);
		
		for(int i=0; i < n; i++) {
			index[a[i]] = i;
		}
		
		for(int i=0; i < n; i++) {
			if (visited[i]) continue;
			
			int cnt = 0;
			int current = a[i];
			
			do {
				current = a[current-1];
				cnt++;
			} while (current != a[i]);
			
			do {
				visited[index[current]] = true;
				ans[index[current]] = cnt;
				
				current = a[current-1];
			} while (current != a[i]);
		}
		
		for(auto x : ans) {
			cout << x << " ";
		}
		
		cout << endl;
	}
}