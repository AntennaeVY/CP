#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		map<int, long long> cnt;
		
		for(auto &ai : a) {
			cin >> ai;
			cnt[ai]++;
		}
		
		int q;
		cin >> q;
		
		while(q--) {
			long long x, y;
			cin >> x >> y;
			
			long long det = x*x - 4*y;
			
			if (det < 0) {
				cout << 0 << " ";
				continue;
			}
			
			if ((long long)sqrtl(det) * (long long)sqrtl(det) != det) {
				cout << 0 << " ";
				continue;
			}
				
			long long num1 = x - sqrtl(det),
					  num2 = x + sqrtl(det);
					  
			if (num1 % 2 || num2 % 2) {
				cout << 0 << " ";
				continue;
			}
				
			num1 /= 2, num2 /= 2;
			
			if (det == 0)
				cout << (cnt[num1] * (cnt[num2] - 1))/2 << " ";
			else
				cout << (cnt[num1] * cnt[num2]) << " ";
		}
		
		cout << endl;
	}
}