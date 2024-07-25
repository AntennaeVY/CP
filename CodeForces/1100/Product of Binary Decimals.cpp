#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		for(int i=31; i >= 2; i--) {
			string s = bitset<5>(i).to_string();
			int x = stoi(s);
			
			while(n % x == 0)
				n /= x;
		}
		
		cout << (n == 1 ? "YES" : "NO") << endl;
	}
}