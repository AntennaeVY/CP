#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	
	int min_weeks = min(a/3, min(b/2, c/2)); 
	
	function<int(int, int, int, int)> cnt_rem;
	cnt_rem = [&](int x, int ar, int br, int cr){
		int cnt = 0, d = x;
		
		while(true) {
			if (d == 0 || d == 3 || d == 6) {
				if (ar == 0)
					break;
					
				ar--;
			}
			
			if (d == 1 || d == 5) {
				if (br == 0)
					break;
					
				br--;
			}
			
			if (d == 2 || d == 4) {
				if (cr == 0)
					break;
					
				cr--;
			}
			
			cnt++, d = (d+1)%7;
		}

		return cnt;
	};
	
	int ans = min_weeks * 7;
	
	a -= 3*min_weeks;
	b -= 2*min_weeks;
	c -= 2*min_weeks;
	
	int mx = 0; 
	
	for(int i=0; i <= 6; i++) {
		mx = max(mx, cnt_rem(i, a, b, c));
	}
	
	cout << ans + mx << endl;
	
}