#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> rooms(n+1);
	for(auto &ri : rooms) cin >> ri;
	
	int l=0, r=n;
	
	int ans = n;
	
	while(l < r && rooms[l] == 0)
		l++, ans--;
		
	while(r > l & rooms[r] == 0)
		r--, ans--;
		
	cout << ans << "\n";
}