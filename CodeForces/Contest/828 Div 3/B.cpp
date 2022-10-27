#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, q;
		cin >> n >> q;
		
		long long sum = 0;
		int odd = 0, even = 0;
	
		vector<int> a(n);
		for(auto &ai:a) {
			cin >> ai;
			sum += ai;
			
			if (ai%2 == 0) 
				even++;
			else
				odd++;
		}
		
		for(int i=0; i < q; i++) {
			int type, x;
			cin >> type >> x;
			
			if (type == 0 && x % 2 == 1) {
				sum += 1LL*x*even;
				odd += even;
				even = 0;
			} else if (type == 0 && x % 2 == 0) {
				sum += 1LL*x*even;
			} else if (type == 1 && x % 2 == 1) {
				sum += 1LL*x*odd;
				even += odd;
				odd = 0;
			} else if (type == 1 && x % 2 == 0) {
				sum += 1LL*x*odd;
			}
			
			cout << sum << endl;
		}
	}
}