#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> a(10);
	for(auto &ai : a) cin >> ai;
	
	int ans = 1;
	for(int i=0; i < 10; i++)
		ans *= (a[i] + 1);
		
	cout << ans - 1 << "\n";
}