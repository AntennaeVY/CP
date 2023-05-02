#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000
using ll = long long;

class DSU {
	private:
		vector<int> parent;
	
	public:
		DSU(int n) {
			parent.assign(n, -1);
		}
		
		int find(int x) {
			int root = x;
			
			while(parent[root] >= 0)
				root = parent[root];
				
			while(x != root) {
				int next = parent[x];
				parent[x] = root;
				x = next;
			}
			
			return root;
		}
		
		void join(int x, int y) {
			x = find(x), y = find(y);
			
			if (x == y)
				return;
				
			if (parent[x] > parent[y])
				swap(x, y);
				
			parent[x] += parent[y];
			parent[y] = x;
		}
};

int main() {
	int N, Q;
	cin >> N >> Q;
	
	vector<int> R(N), C(N);
	for(auto &r : R) cin >> r;
	for(auto &c : C) cin >> c;
		
	DSU r(N), c(N);
	
	for(int i=1; i < N; i++) {
		if (R[i] % 2 == R[i-1] % 2)
			r.join(i, i-1);
			
		if (C[i] % 2 == C[i-1] % 2)
			c.join(i, i-1);
	}
	
	while(Q--) {
		int ra, ca, rb, cb;
		cin >> ra >> ca >> rb >> cb;
		
		ra--, ca--, rb--, cb--;
		
		bool ok = (r.find(ra) == r.find(rb) && c.find(ca) == c.find(cb));
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}