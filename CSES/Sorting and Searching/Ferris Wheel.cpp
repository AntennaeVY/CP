#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	
	vector<int> p(n);
	for(auto &pi : p) cin >> pi;
	
	sort(p.begin(), p.end());
	
	int ans=0, j=n-1;
	
	for(int i=0; i <= j; i++) {
		while(j > i && p[i] + p[j] > x)
			j--, ans++;
			
		j--, ans++;
	}
	
	cout << ans << endl;
}