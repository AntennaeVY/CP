#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		vector<bool> visited(n, 0);
		
		int curr = 0;
		
		for(int i=0; i < min(31, n); i++) {
			int mx = 0, index = -1;
			
			for(int j=0; j < n; j++) {
				if (visited[j]) continue;
				
				if ((curr | a[j]) > mx) {
					mx = (curr | a[j]);
					index = j;
				}
			}
			
			cout << a[index] << " ";
			
			visited[index] = true;
			curr |= a[index];
		}
		
		for(int i=0; i < n; i++) {
			if (!visited[i])
				cout << a[i] << " ";
		}
		
		cout << endl;
	}
}