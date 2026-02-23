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
		
		vector<int> a(n), b(n), c(n);
		for(int i=0; i < n; i++) 
			cin >> a[i] >> b[i] >> c[i];
			
		vector<vector<int>> graph(n);
		vector<int> indegree(n), dp_in(n+1), dp_out(n+1);

		dp_in[n] = -1;
			
		for(int i=0; i < n; i++) {
			for(int j=i+1; j < n; j++) {
				long long A = a[i] - a[j];
				long long B = b[i] - b[j];
				long long C = c[i] - c[j];
				
				long long D = B*B - 4*A*C;
				
				// cout << i << " " << j << " | " << D << ";" << A << endl;
	
				if (D > 0)
					continue;
					
				bool isLine = A == 0 && B == 0;
				
				if (isLine && C > 0 || D < 0 && A > 0) {
					graph[i].push_back(j);
					indegree[j] += 1;
				}
				
				if (isLine && C < 0 || D < 0 && A < 0) {	
					graph[j].push_back(i);
					indegree[i] += 1;
				}
			}
		}
		
		queue<int> q;
		vector<int> toposort;
		
		for(int i=0; i < n; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}
		
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			
			for(auto v : graph[u]) {
				indegree[v] -= 1;
				
				if (indegree[v] == 0)
					q.push(v);
			}
			
			toposort.push_back(u);
		}
		
		for(int i=0; i < n; i++) {
			int u = toposort[i];
			
			for(auto v : graph[u])
				dp_in[v] = max(dp_in[v], dp_in[u] + 1);
		}
		
		for(int i=n-1; i >= 0; i--) {
			int u = toposort[i];
			
			for(auto v : graph[u])
				dp_out[u] = max(dp_out[u], dp_out[v] + 1);	
		}
		
		for(int i=0; i < n; i++)
			cout << dp_in[i] + dp_out[i] + 1 << " ";
		cout << "\n";
		
		// cout << "========" << endl;
		// for(int i=0; i < n; i++) {
			// for(auto j : graph[i])
				// cout << i << " -> " << j << endl;
		// }
	}
}