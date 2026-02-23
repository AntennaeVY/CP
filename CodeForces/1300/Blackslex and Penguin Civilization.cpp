#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int, vector<int>> m;
		
		for(int i=0; i < (1 << n); i++) {
			int cnt = 0;
			
			for(int j=0; j < n; j++) {
				if (((i >> j) & 1)== 0)
					break;
					
				cnt += 1;
			}
			
			m[cnt].push_back(i);
		}
		
		for(auto it = m.rbegin(); it != m.rend(); it++) {
			for(auto &ai : it->second)
				cout << ai << " ";
		}
		
		cout << "\n";
	}
}