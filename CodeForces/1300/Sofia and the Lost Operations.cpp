#include<bits/stdc++.h>
using namespace std;

#define DBG(x) cout<<#x<<" = "<<(x)<<endl;
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) int((x).size())
#define READARR(x) for(auto &xi : (x)) cin >> xi;

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
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		READARR(a); READARR(b);
		
		int m;
		cin >> m;
		
		vector<int> d(m);
		READARR(d);
		
		if (find(ALL(b), d.back()) == b.end()) {
			cout << "NO" << endl;
			continue;
		}
		
		multiset<int> ms;
		
		for(int i=0; i < n; i++) {
			if (a[i] == b[i])
				continue;
				
			ms.insert(b[i]);
		}
		
		for(int i=0; i < m; i++) {
			if (ms.find(d[i]) == ms.end())
				continue;
				
			ms.erase(ms.find(d[i]));
		}
		
		if (ms.size())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}