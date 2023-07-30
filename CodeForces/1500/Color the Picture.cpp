#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,m,k;
		cin >> n >> m >> k;
		
		vector<int> a(k);
		for(auto &ai : a) cin >> ai;
		
		bool can_three = false;
		long long sum = 0;
		
		for(int i=0; i < k; i++) {
			if (a[i] / m >= 2)
				sum += a[i] / m;
			
			if (n % 2) 
				can_three += (a[i] / m) >= 3;
		}
		
		if (sum >= n && (n%2 == 0 || n%2 && can_three)) {
			cout << "Yes" << endl;
			continue; 
		}
		
		swap(n, m);
		can_three = false;
		sum = 0;
		
		for(int i=0; i < k; i++) {
			if (a[i] / m >= 2)
				sum += a[i] / m;
			
			if (n % 2) 
				can_three += (a[i] / m) >= 3;			
		}
		
		if (sum >= n && (n%2 == 0 || n%2 && can_three))
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}	
}