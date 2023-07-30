#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> p(n);
		
		int end = n;
		
		for(int i=n-1; i >= 0; i-=2) {
			p[i] = end--;
		}
		
		int start = 1;
		
		for(int i=n-2; i >= 0; i-=2) {
			p[i] = start++;
		}
		
		for(auto pi : p)
			cout << pi << " ";
			
		cout << endl;
	}
}