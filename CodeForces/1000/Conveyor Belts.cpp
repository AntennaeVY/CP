#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int N, x1, y1, x2, y2;
		cin >> N >> x1 >> y1 >> x2 >> y2;
		
		int l=1, r = N/2 + 1;
		while(l+1 < r) {
			int i = l + (r-l)/2;
			
			if (x1 >= i && x1 <= (N-i+1) && y1 >= i && y1 <= (N-i+1))
				l=i;
			else
				r=i;
		}
		
		int n1 = l;
		
		l=1, r = N/2 + 1;
		
		while(l+1 < r) {
			int i = l + (r-l)/2;
						
			if (x2 >= i && x2 <= (N-i+1) && y2 >= i && y2 <= (N-i+1))
				l=i;
			else
				r=i;
		}
		
		int n2 = l;
	
		cout << abs(n1 - n2) << endl;
	}
}