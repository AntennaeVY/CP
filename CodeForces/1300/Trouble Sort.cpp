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
		
		vector<int> b(n);
		for(auto &bi:b) cin >> bi;
		
		bool sorted = true, distinct = false;
		
		for(int i=1; i < n; i++) {
			if (a[i] < a[i-1])
				sorted = false; 
				
			if (b[i] != b[i-1])
				distinct = true;
		}
		
		if (sorted) {
			cout << "Yes" << endl;
			continue;
		}
		
		if (!distinct) {
			cout << "No" << endl;
			continue;
		}
		
		cout << "Yes" << endl;
	}
}