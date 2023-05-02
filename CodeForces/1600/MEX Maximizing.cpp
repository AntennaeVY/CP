#include <bits/stdc++.h>
using namespace std;

int main() {
  long long q, x;
  cin >> q >> x;
	
  vector<long long> r(x, 0);
  
  set<pair<long long, long long>> s;
  for(int i=0; i < x; i++) {
  	s.insert({0, i});
  }
	
  for(long long i=0; i < q; i++) {
  	long long y;
  	cin >> y;
  	
  	if (x == 1) {
  		cout << i+1 << endl;
  		continue;
  	}
  	
  	s.erase({r[y%x], y%x});
  	r[y%x]++;
  	s.insert({r[y%x], y%x});
  	
	
  	cout << s.begin()->first*x + s.begin()->second << endl;
  }
}