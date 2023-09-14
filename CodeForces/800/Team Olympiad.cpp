#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a,b,c;
	
	for(int i=1; i <= n; i++) {
		int t;
		cin >> t;
		
		if (t == 1)
			a.push_back(i);
		else if (t == 2)
			b.push_back(i);
		else
			c.push_back(i);
	}
	
	int x = min(a.size(), min(b.size(), c.size()));
	
	cout << x << endl;
	
	for(int i=0; i < x; i++) {
		cout << a.back() << " " << b.back() << " " << c.back() << endl;
		
		a.pop_back();
		b.pop_back();
		c.pop_back();
	}
}