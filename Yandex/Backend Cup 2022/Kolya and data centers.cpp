#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,m,q;
	cin >> n >> m >> q;
	
	vector<int> data_center(n, m), reloads(n, 0);
	vector<vector<bool>> server_state(n, vector<bool>(m, true));
	
	vector<bool> default_state(m, true);
	
	for(int i=0; i < q; i++) {
		long long mx = LLONG_MIN;
		long long mn = LLONG_MAX;
		string event;
		cin >> event;
		
		if (event == "RESET") {
			int x;
			cin >> x;
			
			data_center[x-1] = m;
			reloads[x-1] += 1;
			
			server_state[x-1] = default_state;
		}
		
		if (event == "DISABLE") {
			int x, y;
			cin >> x >> y;
			
			if (server_state[x-1][y-1])
				data_center[x-1] = max(0, data_center[x-1] - 1);
				
			server_state[x-1][y-1] = false;
		}
		
		if (event == "GETMAX") {
			int number = 1;
			
			for(int j=0; j < n; j++) {
				if (1LL*data_center[j]*reloads[j] > mx) {
					mx = 1LL*data_center[j]*reloads[j];
					number = j+1;
				};
			}
			
			cout << number << endl;
		}
		
		if (event == "GETMIN") {
			int number = 1;
			
			for(int j=0; j < n; j++) {
				if (1LL*data_center[j]*reloads[j] < mn) {
					mn = 1LL*data_center[j]*reloads[j];
					number = j+1;
				};
			}
			
			cout << number << endl;
		}
	}
}