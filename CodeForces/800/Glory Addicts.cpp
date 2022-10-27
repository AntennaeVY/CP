#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &it:a) cin >> it;
		
		vector<int> fire, frost;
		for(int i{}; i < n; i++) {
			int x; 
			cin >> x;
			
			if (a[i] == 0)
				fire.push_back(x);
			else 
				frost.push_back(x);
		}
		
			sort(fire.rbegin(), fire.rend());
			sort(frost.rbegin(), frost.rend());
			
			int minSize = min(fire.size(), frost.size());
			long long fireDamage = 0, frostDamage = 0;
			
			for(int i=0; i < minSize; i++) {
				fireDamage += fire[i];
				frostDamage += frost[i];
			}
			
			long long ans = 2*fireDamage + 2*frostDamage;
			
			if (minSize < fire.size()) {
				for(int i=minSize; i < fire.size(); i++) {
					ans += fire[i];
				}
			} else if (minSize < frost.size()) {
				for(int i=minSize; i < frost.size(); i++) {
					ans += frost[i];
				}
			} else {
				ans -= min(frost[minSize-1], fire[minSize-1]);
			}
			
			cout << ans << endl;
	}
}