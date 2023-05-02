#include<bits/stdc++.h>
using namespace std;

int main() {
	int k, r;
	cin >> k >> r;
	
	for(int i=1; i <= 10; i++) {
		int dig = k%10;
		
		if ((dig * i) % 10 == 0 || (dig * i) % 10 == r){
			cout << i << endl;
			return 0;
		} 
	}
}