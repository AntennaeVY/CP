#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		deque<pair<int,int>> j;
		priority_queue<int> pq;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			j.push_back({x, i});
			pq.push(x);
		}
		
		int time = 0;
		
		while(!pq.empty()) {
			if (pq.top() != j.front().first) {
				j.push_back(j.front());
				j.pop_front();
				
				
				continue;
			}
			
			time++;
			
			if (j.front().second == m) {
				cout << time << endl;
				break;
			}
			
			j.pop_front();
			pq.pop();
		}
	}
}