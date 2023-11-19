#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		vector<int> a(3);
		
		for (auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		bool ok = true;
		
		if (a[1] != a[2])
			ok = false;
			
		if (!ok) 
			cout << "NO" << endl;
		else
			cout << "YES" << endl << a[0] << " " << a[0] << " " << a[2] << endl;
	}
	
	return 0;
}