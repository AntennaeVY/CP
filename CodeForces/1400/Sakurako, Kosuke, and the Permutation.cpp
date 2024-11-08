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
		
		vi a(n+1);
		for(int i=1; i <= n; i++) {
			cin >> a[i];
		}
		
		vector<bool> vis(n+1, false);
		int ans = 0;
		for(int i=1; i <= n; i++) {
			if (vis[i])
				continue;
				
			int cnt = 0;
			
			int j = i;
			while(!vis[j]) {
				vis[j] = true;
				
				j = a[j], cnt++;
			}
			
			if (cnt > 2) {
				ans += (cnt + 1)/2 - 1;
			}
		}
		
		cout << ans << endl;
	}
}