#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	vector<int> bits(32, 0);

	for(int i=0; i < n; i++) {
		for(int j=0; j < 32; j++) {
			if (a[i] & (1 << j))
				bits[j]++;
		}
	}
	
	for(int i=0; i < n; i++) {
		int x = 0;
		
		for(int j=0; j < 32; j++) {
			if (bits[j])
				x += (1 << j), bits[j]--;
		}
		
		cout << x << " ";
	}
	
	cout << endl;
}