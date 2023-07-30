#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	sort(a.begin(), a.end());

	int i=1, j=0, ans=0;
	
	while(true) {
		while(j < n && i > a[j]) j++;
		
		if (j == n)
			break;
			
		a[j] -= i;
		i++, j++, ans++;
	}
	
	cout << ans << endl;
}