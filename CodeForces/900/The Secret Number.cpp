#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		long long n;
		cin >> n;
		
		long long ten = 10;
		
		vector<long long> ans;
		
		for(int i=0; i < 18; i++) {
			if (n % (1+ten) == 0)
				ans.push_back(n / (1+ten));
			
			ten *= 10;
		}
		
		cout << ans.size() << "\n";
		
		sort(ans.begin(), ans.end());
		
		for(auto &ansi : ans)
			cout << ansi << " ";
			
		if (ans.size())
			cout << "\n";
		
	}
}