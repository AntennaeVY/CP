#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		deque<int> dq;
		
		for(int i=0; i < n; i++) {
			dq.push_back(a[i]);
		}
		
		while(dq.size() > 1) {
			int a = dq.front();
			int b = dq.back();
			int c = a+b-1;
			
			dq.pop_back();
			dq.pop_front();
			
			dq.push_back(c);
		}
		
		cout << dq.front() << endl;
	}
}