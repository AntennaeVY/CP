#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, s, r;
		cin >> n >> s >> r;
		
		cout << s - r << " ";
		
		int rem = r % (n-1);
		
		vector<int> a(n-1, r/(n-1));
		
		for(int i=0; i < a.size(); i++) {
			if (a[i] > (s - r)) {
				a[i]--;
				rem++;
			}
			
			if (rem && a[i] < s-r) {
				int add = min(rem, (s-r) - a[i]);
				
				a[i] += add;
				rem -= add;
			}
		}
		
		for(auto &ai : a)
			cout << ai << " ";
			
		cout << endl;
	
	}
}