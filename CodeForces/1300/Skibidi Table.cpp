#include <bits/stdc++.h>
using namespace std;

long long recursion(long long x, long long y, long long m) {
  long long quadrant;

  if (x <= m / 2 && y <= m / 2) 
  	quadrant = 1;

  if (x > m / 2 && y > m / 2) 
	quadrant = 2;

  if (x > m / 2 && y <= m / 2) 
	quadrant = 3;

  if (x <= m / 2 && y > m / 2) 
	quadrant = 4;
	
   if (m == 1)
   	return quadrant;
	
  if (x > m/2)
  	x -= m/2;

  if (y > m/2)
  	y -= m/2;
	
   return (quadrant - 1) * (m/2) * (m/2) + recursion(x,y,m/2);
}

pair<long long, long long> recursion2(long long x, long long m) {
	if (m == 1) {
		return {1, 1};
	}
	
	if (x > 3LL*(m/2)*(m/2)) {
		pair<long long, long long> p = recursion2(x - 3LL*(m/2)*(m/2), m/2);
		
		
		p.second += m/2;
		
		return p;
	} else if (x > 2LL*(m/2)*(m/2)) {
		pair<long long, long long> p = recursion2(x - 2LL*(m/2)*(m/2), m/2);
		
		p.first += m/2;
		
		return p;
	} else if (x > (m/2)*(m/2)) {
		
		
		// cout << x << " " << m << endl;
		pair<long long, long long> p = recursion2(x - (m/2)*(m/2), m/2);
		
		
		
		
		p.first += m/2, p.second += m/2;
		
		return p;
	} else {
		return recursion2(x, m/2);
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int q;
    cin >> q;

    while (q--) {
      string d;
      cin >> d;

      if (d == "->") {
        long long x, y;
        cin >> x >> y;
        
        long long m = 1;

	 	while (m < max(x, y)) m <<= 1;
	        
        cout << recursion(x, y, m) - 1 << endl;

      } else {
        long long x;
        cin >> x;        
        
        long long m = 1;
	 	while (x > m*m) m <<= 1;
	 	
	 	pair<long long, long long> p = recursion2(x, m);
        
        cout << p.first << " " << p.second << endl;
      }
    }
  }
}