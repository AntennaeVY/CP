#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int odd = count_if(a.begin(), a.end(), [&](int x){ return x % 2;});
		
		if (n % 2 == 0 && odd == n)
			cout << "NO" << endl;
		else if (odd >= 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}