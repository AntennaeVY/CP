#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	
	for(int i=0; i < n; i++) {
		cin >> a[i];
	}
	
	int mn = INT_MAX, t = 0;
	
	for(int i=0; i <= 100; i++) {
		int cost = 0;
		
		for(int j=0; j < n; j++) {
			if (a[j] != i)
			cost += abs(a[j]-i) - 1; 
		}
		
		if (min(mn, cost) == cost) {
			mn = cost;
			t = i;
		}
	}
	
	cout << t << " " << mn << endl;
}