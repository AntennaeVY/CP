#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	 cin >> t;
	 
	 while(t--) {
	 	int n;
	 	cin >> n;
	 	
	 	vector<int> a(n);
	 	for(auto &ai:a) cin >> ai;
	 	
	 	if (a[0] != n && a.back() != n) {
	 		cout << -1 << endl;
	 		continue;
	 	}
	 	
	 	deque<int> ans;
	 	
	 	int l=0, r=n-1;
	 	
	 	while(l <= r) {
	 		if (a[l] >= a[r]) {
	 			ans.push_front(a[l]);
	 			l++;
	 		} else {
	 			ans.push_back(a[r]);
	 			r--;
	 		}
	 	}
	 	
	 	for (auto x : ans) {
	 		cout << x << " ";
	 	}
	 	
	 	cout << endl;
	 }
}