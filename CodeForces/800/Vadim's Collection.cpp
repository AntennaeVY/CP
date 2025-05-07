#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		vector<int> cnt(11, 0);
		for(int i=0; i < s.size(); i++)
			cnt[s[i] - '0']++;
		
		for(int i=1; i <= 10; i++)
			for(int j=10-i; i <= 10; j++) {
				if (!cnt[j])
					continue;
				
				cout << j;
				cnt[j]--;
				break;
			}
			
		cout << endl;
	}
}