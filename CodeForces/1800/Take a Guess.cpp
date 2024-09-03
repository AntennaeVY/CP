#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> v(n);
	
	cout << "or 1 2" << endl;
	cout << "or 2 3" << endl;
	cout << "and 1 2" << endl;
	cout << "and 1 3" << endl;
	
	int aUb, bUc, aNb, aNc;
	cin >> aUb >> bUc >> aNb >> aNc;
	
	int a = aUb & (~bUc) | aNb | aNc;
	int b = aUb & (~a) | aNb;
	
	v[0] = a, v[1] = b;
	
	for(int i=3; i <= n; i++) {
		cout << "or 1 " + to_string(i) << endl;
		cout << "and 1 " + to_string(i) << endl;
		
		int aUx, aNx;
		cin >> aUx >> aNx;
		
		v[i-1] = aUx & (~a) | aNx;
	}
	
	sort(v.begin(), v.end());
	
	cout << "finish " + to_string(v[k-1]) << endl;
}