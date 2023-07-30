#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(int i=0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		
	 	int l=1, r=n+1;
	 	while(l+1 < r) {
	 		int x = l + (r-l)/2;
	 		
	 		int cnt = 0;
	 		for(int i=0; i < n; i++) { 			
	 			if (a[i] >= x-cnt-1 && b[i] >= cnt)
	 				cnt++;
	 		}
	 		
	 		if (cnt >= x)
	 			l=x;
	 		else 
	 			r=x;
	 	}
	 	
	 	cout << l << endl;
	}
}