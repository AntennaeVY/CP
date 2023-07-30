#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> positive, negative, total;
		map<int, bool> m;
		
		bool ok = true;
		
		for(int i=0; i < n; i++) {
			int x; 
			cin >> x;
			
			if (positive.size() > 2 || negative.size() > 2)
				ok = false;
				
			m[x] = true;
				
			if (x > 0)
				positive.push_back(x);
			else if (x < 0)
				negative.push_back(x);
			else if (total.size() < 2)
				total.push_back(x);
		}
		
		if (!ok) {
			cout << "NO" << endl;
			continue;
		}
		
		for(auto x : positive) {
			total.push_back(x);
		}
		
		for(auto x : negative) {
			total.push_back(x);
		}
		
		for(int i=0; i < total.size(); i++) {
			for(int j=i+1; j < total.size(); j++) {
				for(int k=j+1; k < total.size(); k++) {
					if (m[total[i] + total[j] + total[k]] == false) {
						ok = false;
					}
				}
			}
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}