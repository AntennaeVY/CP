#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	map<char, int> cnt;
	stack<int> zero;
	queue<int> two;
	
	for(int i=0; i < n; i++) {			
		cnt[s[i]]++;
	}
	
	for(int i=0; i < n; i++) {
		if (cnt['0'] >= n/3)
			break;
		
		if (s[i] != '0' && cnt[s[i]] > n/3)
			cnt['0']++, cnt[s[i]]--, s[i] = '0';	
	}
	
	for(int i=n-1; i >= 0; i--) {
		if (cnt['2'] >= n/3)
			break;
			
		if (s[i] != '2' && cnt[s[i]] > n/3)
			cnt['2']++, cnt[s[i]]--, s[i] = '2';
	}
	
	for(int i=0; i < n; i++) {
		if (s[i] == '0')
			zero.push(i);
		else if (s[i] == '2')
			two.push(i);
	}
	
	while(cnt['1'] < n/3) {
		if (cnt['0'] > n/3) {
			int i = zero.top();
			zero.pop();
			
			s[i] = '1', cnt['0']--, cnt['1']++;
		}
		
		if (cnt['2'] > n/3) {
			int i = two.front();
			two.pop();
			
			s[i] = '1', cnt['2']--, cnt['1']++;
		}
	}
	
	cout << s << endl;
}