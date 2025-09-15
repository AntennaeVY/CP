#include<bits/stdc++.h>
using namespace std;

bool is_valid(string &s) {
	int hypens = count(s.begin(), s.end(), '-');
	int x = count(s.begin(), s.end(), 'X');
	
	if (x > 1)
		return false;
		
	if (x == 1 && s.back() != 'X')
		return false;
	
	if (hypens > 3)
		return false;
		
	if (s.size() - hypens != 10)
		return false;
		
	if (s[0] == '-' || s.back() == '-')
		return false;
		
	if (hypens == 3 && s[s.size() - 2] != '-')
		return false;
		
	for(int i=1; i < s.size(); i++) {
		if (s[i] == '-' && s[i-1] == '-')
			return false;
	}
		
	int d = 10, sum = 0;
	for(int i=0; i < s.size(); i++) {
		if (isdigit(s[i]) || s[i] == 'X') {
			int v = s[i] - '0';
			
			if (s[i] == 'X')
				v = 10;
			
			sum += v * d;
			d--;
		}
	}
	
	return sum % 11 == 0;
}

string convert(string &s) {
	string ans = "978-";
	
	for(int i=0; i < s.size() - 1; i++)
		ans += s[i];
		
	int sum = 0, d = 1;
	for(int i=0; i < ans.size(); i++) {
		int v = ans[i] - '0';
		
		if (ans[i] == '-')
			continue;
		
		if (d % 2) {
			sum += v;
		} else  {
			sum += 3 * v;
		}
			
		d++;
	}
	
	ans += ((10 - (sum % 10)) % 10  + '0');
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		if (!is_valid(s)) {
			cout << "invalid\n";
			continue;
		}
		
		cout << convert(s) << "\n";
	}
}