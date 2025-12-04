#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, x;
	cin >> a >> x;
	
	int n = 0;
	for(int i=2; i <= a; i++) {
		if (i > x)
			break;
		
		while(a % i == 0) 
			a /= i, n++;
	}
	
	if (a != 1)
		cout << "what is Obo?";
	else 
		cout << n;
		
	cout << "\n";
}