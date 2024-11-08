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
		int n;
		cin >> n;
		
		vector<vi> a(n, vector<int>(n));
		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			int mn = 0;
			
			int j=0, k=i;
			
			while(k < n) {
				mn = min(mn, a[j][k]);
				
				// cout << j << " " << k << endl;
				
				j++, k++;
			}
			
			ans += abs(mn);
		}
		
		for(int i=1; i < n; i++) {
			int mn = 0;
			
			int j=0, k=i;
			
			while(k < n) {
				mn = min(mn, a[k][j]);
				
				j++, k++;
			}
			
			ans += abs(mn);
		}
		
		cout << ans << endl;
	}
}