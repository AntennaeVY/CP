#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), two;
		for(int i=0; i < n; i++) {
			 cin >> a[i];
			 
			 if (a[i] == 2)
			 	two.push_back(i+1);
		}
		
		if (two.size() % 2)
			cout << -1 << endl;
		else if (two.size())
			cout << two[(two.size()-1)/2] << endl;
		else
			cout << 1 << endl;
	}
}