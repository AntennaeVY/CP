#include<bits/stdc++.h>
using namespace std;

#define DBG(x) cout<<#x<<" = "<<(x)<<endl;
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SZ(x) int((x).size())
#define READARR(x) for(auto &xi : (x)) cin >> xi;
#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define vi vector<int>
#define vll vector<long long>
#define ll long long

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
	// cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		sort(a.rbegin(), a.rend());
		
		vector<int> cnt(m, 0);
		
		int j = 0;
		
		for(int i=0; i < m && j < n; i++, j++) {
			cnt[i] += a[j];
		}
		
		for(int i=m-1; i >= 0 && j < n; i--, j++) {
			cnt[i] += a[j];
		}
		
		cout << *max_element(cnt.begin(), cnt.end()) << endl;
	}
}