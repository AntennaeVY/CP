#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<vector<ll>> pyramid(2024, vector<ll>(2024, 0));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	ll x=1;
	for(int j=1; j <= 2023; j++) {
		int i = j;
		
		for(int k=1; k <= j; k++, i--, x++) {
			pyramid[i][k] = pyramid[i][k-1] + pyramid[i-1][k] - pyramid[i-1][k-1] + x*x;
		}
	}
	
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int l=0, r=2023;
		
		while(r-l > 1) {
			int mid = l + (r-l)/2;
			
			if ((mid * (mid+1))/2 >= n) 
				r = mid;
			else
				l = mid;
		}
		
		int j = r - ((r*(r+1))/2 - n);
		int i = 1 + ((r*(r+1))/2 - n);
		
		cout << pyramid[i][j] << endl;
	}
}