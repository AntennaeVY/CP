#include<bits/stdc++.h>
using namespace std;

int to_base(int a, int b) {
	int p = 1;
	int ans = 0;
	
	while(a) {
		int d = a % 10;
		a /= 10;
		
		ans += d * p;
		p *= b;
	}
	
	return ans;
}

bool is_valid(int a, int b) {
	while(a) {
		int d = a % 10;
		a /= 10;
		
		if (d >= b)
			return false;
	}
	
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x, y, s;
	cin >> x >> y >> s;
	
	for(int i=2; i <= 10; i++) {
		if (!is_valid(x, i))
			continue;
		
		for(int j=2; j <= 10; j++) {
			if (!is_valid(y, j))
				continue;
				
			int sum = to_base(x, i) + to_base(y, j);
			
			if (sum == s) {
				cout << i << " " << j << "\n";
				return 0;
			}
		}
	}
}