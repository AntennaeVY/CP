#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int age1, age2;
	int amount1, amount2;
	
	cin >> age1 >> amount1;
	cin >> age2 >> amount2;
	
	int limit;
	cin >> limit;
	
	int option1 = max(0, limit - age1) * amount1;
	int option2 = max(0, limit - age2) * amount2;
	
	if (option1 >= option2)
		cout << 1 << "\n";
	else
		cout << 2 << "\n";
}