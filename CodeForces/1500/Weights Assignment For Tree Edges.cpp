#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int, int> parent_of;
		vector<int> b(n);
	
		for(int i=0; i < n; i++) {
			cin >> b[i];
				
			parent_of[i+1] = b[i];
		}
		
		map<int, int> index_of;
		vector<int> p(n);
		
		for(int i=0; i < n; i++) {
			cin >> p[i];
			
			index_of[p[i]] = i;
		}
		
		bool ok = true;
		vector<int> dist(n);
		
		for(int i=0; i < n; i++) {
			if (index_of[parent_of[p[i]]] > i)
				ok = false;
				
			dist[p[i]-1] = i; 
		}
		
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		
		vector<int> w(n);
		
		for(int i=0; i < n; i++) {
			w[i] = dist[i] - dist[b[i]-1];
		}
		
		for(int wi : w) {
			cout << wi << " ";
		}
		
		cout << endl;
	}
}