#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> p(n);
	for(int i=0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	
	for(int i=0; i < n; i++) {
		vector<bool> f(n);
		
		int j = i;
		
		while(!f[j])
			f[j] = true, j = p[j];
			
		cout << j+1 << " ";
	}
	
	cout << endl;
}