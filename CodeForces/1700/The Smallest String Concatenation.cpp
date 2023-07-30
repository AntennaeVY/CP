#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<string> a(n);
	for(auto &ai : a) cin >> ai;
	
	sort(a.begin(), a.end(), [&](string x, string y){
		bool pref = true;
		
		for(int i=0; i < min(x.size(), y.size()); i++) {
			pref &= (x[i] == y[i]);
		}
		
		if (!pref)
			return x < y;
			
		return (x + y) < (y + x);
	});
	
	string ans = "";
	
	for(int i=0; i < n; i++) {
		ans += a[i];
	}
	
	cout << ans << endl;
}