#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		vector<int> a(26, 0);
		
		
		for(int i=0; i < n; i++) {
			int j = s[i] - 65;
			
			if (a[j] == 0)
				a[j] += 2;
			else
				a[j]++;
		}
		
		cout << accumulate(a.begin(), a.end(), 0) << endl;
	}
}