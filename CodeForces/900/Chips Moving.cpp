#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int odd = 0, even = 0;
	
	for(int i=0; i < n; i++) {
		odd += a[i] % 2;
		even += !(a[i] % 2);
	}
	
	cout << min(odd, even) << endl;
}