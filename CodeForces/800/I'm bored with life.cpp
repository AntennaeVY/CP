#include<bits/stdc++.h>
using namespace std;

int factorial(int x) {
	int ans = 1;
	
	for(int i=2; i <= x; i++) {
		ans *= i;
	}
	
	return ans;
}

int main() {
	int a, b;
	cin >> a >> b;
	
	if (a > b)
		swap(a, b);
		
	cout << factorial(a) << endl;
}