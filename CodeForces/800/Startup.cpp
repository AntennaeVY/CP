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
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vi b(k), c(k);
		
		map<int, int> m;
		
		for(int i=0; i < k; i++) {
			cin >> b[i] >> c[i];
		
			m[b[i]] += c[i];
		}
		
		vi a;
		for(auto [brand, cost] : m) {
			a.push_back(cost);
		}
		
		sort(a.rbegin(), a.rend());
		
		int ans = 0, cnt = 0;;
		
		for(int i=0; i < a.size(); i++) {
			if (cnt == n)
				break;
				
			ans += a[i], cnt++;
		}
		
		cout << ans << endl;
	}
}