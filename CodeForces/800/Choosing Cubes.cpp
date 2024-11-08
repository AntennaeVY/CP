#include<bits/stdc++.h>
using namespace std;

#define DBG(x) cout<<#x<<" = "<<(x)<<endl;
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) int((x).size())

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"[ ";
    for(auto y : v) out<<y<<" ";
    out<<"]";
    return out;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, f, k;
		cin >> n >> f >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int val = a[f-1];
		
		sort(a.rbegin(), a.rend());
		
		if (k < n && (val < a[k] || val == a[k] && val < a[k-1]))
			cout << "NO" << endl;
		else if (k == n || val > a[k])
			cout << "YES" << endl;
		else if (val == a[k] && val == a[k-1]) 
			cout << "MAYBE" << endl;
		
	}
}