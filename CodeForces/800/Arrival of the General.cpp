#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int m = *min_element(a.begin(), a.end());
	int M = *max_element(a.begin(), a.end());
	
	int mi = -1, Mi = n;
	
	for(int i=0; i < n; i++) {
		if(a[i] == m)
			mi = max(mi, i);
			
		if(a[i] == M)
			Mi = min(Mi, i);
		  
	}
	
	if (mi > Mi)
		cout << (n-1-mi + Mi) << endl;
	else
		cout << n-1-mi + Mi -1 << endl;
}