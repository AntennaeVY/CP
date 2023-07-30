#include<bits/stdc++.h>
using namespace std;

int cost(string &s, char c, int l, int r) {
	if (l == r) {
		return s[l] == c ? 0 : 1;
	}
	
	int mid = (r+l+1)/2;
	int count_left = count(s.begin()+l, s.begin()+mid, c);
	int count_right = count(s.begin()+mid, s.begin()+r+1, c);
	
	int cost_left = (mid - l - count_left) + cost(s, c+1, mid, r);
	int cost_right = (r - mid + 1 - count_right) + cost(s, c+1, l, mid-1);
	
	return min(cost_left, cost_right);
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		cout << cost(s, 'a', 0, s.size()-1) << endl;
	}
}