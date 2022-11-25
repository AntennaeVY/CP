#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int sq = 0, rct = 0;
  map<int,int> cnt;
  
  for(int i=0; i < n; i++) {
  	int x;
  	cin >> x;
  	
  	sq -= cnt[x] / 4;
  	rct -= cnt[x] / 2;
  	
  	cnt[x]++;
  	
  	sq += cnt[x] / 4;
  	rct += cnt[x] / 2;
  }
  
  int q;
  cin >> q;
  
  while(q--) {
  	char op;
  	int x; 
  	
  	cin >> op >> x;
  	
  	sq -= cnt[x] / 4;
  	rct -= cnt[x] / 2;	
  	
  	if (op == '+')
  		cnt[x]++;
  	else
  		cnt[x]--;
  		
  	sq += cnt[x] / 4;
  	rct += cnt[x] / 2;

	if (sq >= 1 && rct >= 4)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
  }
}