#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		long long n;
		cin >> n;
		 
		long long num = n;
		string s = "";
		
		while(num) {
			s = s + (char)(48 + num % 3);
			num /= 3;
		}
		
		int cnt = 0;
		
		for(int i=0; i < s.size(); i++) {
			if (s[i] == '2')
				cnt++;
		}
		
		
		long long pow = 1, add = 0, carry = 0;
		
		for(int i=0; i < s.size(); i++) {
			int dig = s[i] - 48;
			
			if (dig + carry == 1) {
				if (cnt > 0)
					add += 2*pow, carry = 1;
				else
					carry = 0;
			} else if (dig + carry == 2) {
				add += pow;
				carry = 1;
			}
			
			if (dig == 2)
				cnt--;
				
			pow *= 3;
		}
		
		cout << n + add << endl;
	}
}