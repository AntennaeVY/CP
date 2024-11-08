#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	long long sum = 1LL * 25 * (n / 5);
	
	if (n % 5 == 1)
		sum += 1;
	else if (n % 5 == 2)
		sum += 1 + 3;
	else if (n % 5 == 3)
		sum += 1 + 3 + 5;
	else if (n % 5 == 4)
		sum += 1 + 3 + 5 + 7;
		
	cout << sum << endl;
}