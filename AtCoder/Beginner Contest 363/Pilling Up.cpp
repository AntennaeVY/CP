#include<bits/stdc++.h>
using namespace std;

int main() {
	int r;
	cin >> r;
	
	int ans = 1e9;
	
	vector<int> ratings = {100, 200, 300};
	
	for(auto rating : ratings)
	 	if (r < rating)
		ans = min(ans, rating - r);
		
	cout << ans << endl;
}