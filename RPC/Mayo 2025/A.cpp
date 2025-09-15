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
		
		multiset<long long> ms;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		for(auto &ai : a) ms.insert(ai);
		
		long long result = 0;
		
		while(ms.size() >= 2) {
			long long x = *ms.begin();
			ms.erase(ms.begin());
			
			long long y = *ms.begin();
			ms.erase(ms.begin());
			
			ms.insert(x+y);
			result += x+y;
		}
		
		cout << result << "\n";
	}
}