#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a;
		map<int, int> cnt;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			if (cnt[x % 10] < 3) {
				cnt[x % 10]++;
				a.push_back(x % 10);
			}
		}
		
		bool ok = false;
		
		for(int i=0; i < a.size(); i++) {
			for(int j=i+1; j < a.size(); j++) {
				for(int k=j+1; k < a.size(); k++) {
					int sum = a[i] + a[j] + a[k];
					
					if (sum % 10 == 3)
						ok = true;
				}
			}
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}