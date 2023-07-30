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
		
		long long sum = 0;
		for(int i=0; i < n; i++) {
			if (s[i] == 'L')
				sum += i;
			else
				sum += n-i-1;
		}
		
		int l=0, r=n-1;
		
		for(int i=0; i < n; i++) {
			int changeL = 0, changeR = 0;
			
			while(l < n && s[l] != 'L') l++;
			while(r >= 0 && s[r] != 'R') r--;
			
			if (l < n) {
				changeL = n-l-1 - l;
			}
			
			if (r >= 0) {
				changeR = r - (n-r-1);
			}
			
			if (changeL >= changeR && max(changeL, changeR) >= 0)
				l++;
			else
				r--;
				
			sum += max(max(changeL, changeR), 0);
			cout << sum << " ";
		}
		
		cout << endl;
	}
}