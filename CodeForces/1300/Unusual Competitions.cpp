#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int sum = 0, ans = 0;
	
	for(int i=0; i < n; i++) {
		if (s[i] == '(')
			sum += 1;
		else 
			sum -= 1;
	}
	
	if (sum != 0) {
		cout << -1 << endl;
		return 0;
	}
	
	int bad_index = -1;
	
	for(int i=0; i < n; i++) {
	 	if (s[i] == '(') 
			sum += 1;
		else
			sum -= 1;
			
		if (sum == -1 && bad_index == -1) {
			bad_index = i;
		} else if (sum == 0 && bad_index != -1) {
			ans += i-bad_index+1;
						
			sum = 0;
			bad_index = -1;
		}
	}
	
	cout << ans << endl;
}