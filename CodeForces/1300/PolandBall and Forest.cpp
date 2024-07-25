#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> p(n);
	for(int i=0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	
	set<pair<int,int>> s;
	
	for(int i=0; i < n; i++) {
		int a = p[i];
		int b = p[p[i]];
		
		s.insert({min(a,b), max(a,b)});
	}
	
	cout << s.size() << endl;
}