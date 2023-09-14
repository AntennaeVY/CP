#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string str;
		cin >> str;
		
		vector<int> cnt(27, 0);
		for(auto c : str) cnt[c - 'a']++;
		
		int n = str.size();
		string t_max = string(str.size(), '$');
		
		int p=0, s=n-1;
		
		for(int i=0; i < 26; i++) {
			while(cnt[i] >= 2)
				t_max[p++] = t_max[s--] = 'a' + i, cnt[i] -= 2;
			
			if (cnt[i] == 0)
				continue;
				
			if (p == s) {
				t_max[p] = 'a' + i, cnt[i]--;
				break;
			}
			
			int j = i+1;
			while(cnt[j] == 0) j++;
			
			if (cnt[j] == s-p) {
				while(cnt[j] >= 2) 
					t_max[p++] = t_max[s--] = 'a' + j, cnt[j] -= 2;
					
				if (cnt[j] == 1)
					t_max[p++] = 'a' + j, cnt[j]--;
					
				t_max[s--] = 'a' + i;
			} else {
				for(int k=j; k < 26; k++) {
					while(cnt[k]--)
						t_max[p++] = 'a' + k;
				}
				
				t_max[s--] = 'a' + i;
			}
			
			break;
		}
		
		cout << t_max << endl;
	}
}