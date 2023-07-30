#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> odd, even;
	
	for(int i=1; i <= n; i++) {
		int x;
		cin >> x;
		
		if (x & 1)
			odd.push_back(i);
		else
			even.push_back(i);
	}
	
	cout << (odd.size() == 1 ? odd[0] : even[0]) << endl;
}