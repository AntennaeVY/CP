#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		vector<string> s(2);
		cin >> s[0] >> s[1];
		
		int t, Q;
		cin >> t >> Q;
		
		map<int, bool> bad;
		int cnt = 0;
		
		for(int i=0; i < s[0].size(); i++) {
			if (s[0][i] != s[1][i])
				bad[i] = true, cnt++;
		}
		
		int time = 0;
		queue<pair<int,int>> q;
		
		while(Q--) {
			if (!q.empty()) {
				auto &[i, ti] = q.front();
				
				if (ti == time) {
					bad[i] = (s[0][i] != s[1][i]);
					cnt += bad[i];
					
					q.pop();
				}
			}
			
			int op;
			cin >> op;
			
			if (op == 1) {
				int pos;
				cin >> pos;
				
				pos--;
				cnt -= bad[pos];
				
				q.push({pos, time+t});
			} else if (op == 2) {
				int t1, t2, pos1, pos2;
				cin >> t1 >> pos1 >> t2 >> pos2;
				
				t1--, t2--, pos1--, pos2--;
				
				if (s[t1][pos1] != s[1 - t1][pos1])
					cnt--, bad[pos1] = false;
				
				if (s[t2][pos2] != s[1 - t2][pos2])
					cnt--, bad[pos2] = false; 
				
				swap(s[t1][pos1], s[t2][pos2]);
				
				if (s[t1][pos1] != s[1 - t1][pos1])
					cnt++, bad[pos1] = true;
				
				if (s[t2][pos2] != s[1 - t2][pos2])
					cnt++, bad[pos2] = true; 
				
			} else {
				cout << (cnt == 0 ? "YES" : "NO") << endl;
			}
		
			time++;
		}
	}
}