#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	set<int> s;
	
	for(int i=0; i < n; i++) {
		while(a[i] % 2 == 0)
			a[i] /= 2;
			
		while(a[i] % 3 == 0)
			a[i] /= 3;
			
		s.insert(a[i]);
	}
	
	cout << (s.size() == 1 ? "YES" : "NO") << endl;
}