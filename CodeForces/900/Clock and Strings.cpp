#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		
		if (b < a)
			swap(a, b);
			
		if (d < c)
			swap(d, c);
			
		bool are_both_inside = (c >= a && c <= b && d >= a && d <= b);
		bool are_both_outside = ((c > b || c < a) && (d > b || d < a));
			
		if (are_both_inside || are_both_outside)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}