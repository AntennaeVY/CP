#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	set<int> X, Y;
	
	for(int i=0; i < n; i++) {
		int d;
		cin >> d;
		
		if (X.count(d))
			Y.insert(d);
		else
			X.insert(d);
	}
	
	int x = *max_element(X.begin(), X.end());
	
	for(int i=1; i*i <= x; i++) {
		if (x % i == 0) {
			X.erase(i); 
			X.erase(x/i);
		}
	}
	
	int y = max(*max_element(X.begin(), X.end()), *max_element(Y.begin(), Y.end()));
	
	cout << x << " " << y << endl;
}