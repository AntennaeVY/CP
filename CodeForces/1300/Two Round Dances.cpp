#include<bits/stdc++.h>
using namespace std;

long long fact(int x) {
	long long ans = 1;
	for(int i=2; i <= x; i++)
		ans *= i;
		
	return ans;
}

int main() {
	int n;
	cin >> n;
	
	cout << 2*fact(n)/(n*n) << endl;
}