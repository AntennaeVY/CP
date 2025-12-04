#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string n;
		cin >> n;
		
		int j, k;
		cin >> j >> k;
		
		j--, k--;
		
		vector<string> p;
		
		do {
			p.push_back(n);
		} while(next_permutation(n.begin(), n.end()));
		
		vector<int> vx(n.size()), vy(n.size());
		for(int i=0; i < n.size(); i++) {
			vx[p[j][i] - '1']++;
			vy[p[k][i] - '1']++;
		}
		
		int a = 0, b = 0;
		for(int i=0; i < n.size(); i++) {
			if (p[j][i] == p[k][i])
				a++, vx[p[j][i] - '1']--, vy[p[k][i] - '1']--; 
		}
		
		for(int i=0; i < n.size(); i++) {
			if (vx[i] > 0 && vy[i] > 0)
				b++;
		}
		
		cout << a << "A" << b << "B" << "\n";
	}
}