#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> a(n), b(n);
	for(auto &ai : a) cin >> ai;
	for(auto &bi : b) cin >> bi;
	
	multiset<int> ms;
	for(int i=0; i < n; i++)
		ms.insert(b[i]);
		
	vector<int> c(n);
		
	for(int i=0; i < n; i++) {
		int x = n - a[i];
		
		auto it = ms.lower_bound(x);
		
		if (it == ms.end() || (a[i] + *it) % n > (a[i] + *ms.begin()) % n) {
			it = ms.begin();
		}
		
		c[i] = (a[i] + *it) % n;
		ms.erase(it);
		
		cout << c[i] << " ";
	}
	
	cout << "\n";
}