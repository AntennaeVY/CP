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
	
	while(t--) {
		int n, k, q;
		cin >> n >> k >> q;
		
		vector<vector<int>> v(n, vector<int>(k));
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < k; j++) {
				cin >> v[i][j];
			}
		}
		
		vector<vector<long long>> mx(n, vector<long long>(k));
		
		for(int i=0; i < k; i++) 
			mx[0][i] = v[0][i];
		
		for(int i=1; i < n; i++) {
			for(int j=0; j < k; j++) {
				mx[i][j] = (v[i][j] | mx[i-1][j]);
			}
		}
		
		// for(int i=0; i < n; i++) {
			// for(int j=0; j < k; j++) {
				// cout << mx[i][j] << " ";
			// }
			// cout << endl;
		// }
		
		while(q--) {
			int m;
			cin >> m;

			vector<int> R(m), C(m);
			vector<char> O(m);
			
			for(int i=0; i < m; i++) {
				long long r, c;
				char o;
				cin >> r >> o >> c;
				
				r--;
				R[i] = r, O[i] = o, C[i] = c;
			}
			
			int l=-1, r=n;
			while(l+1 < r) {
				int x = l + (r-l)/2;
				
				bool can = true;
				
				for(int i=0; i < m; i++) {
					if (O[i] == '>')
						can &= (mx[x][R[i]] > C[i]);
				}
				
				if (!can)
					l = x;
				else
					r = x;
			}
			
			int X = r;
			
			l=-1, r=n;
			while(l+1 < r) {
				int x = l + (r-l)/2;
				
				bool can = true;
				
				for(int i=0; i < m; i++) {
					if (O[i] == '<')
						can &= (mx[x][R[i]] < C[i]);
				}
				
				if (!can)
					r = x;
				else
					l = x;
			}
			
			if (l < X)
				cout << -1 << endl;
			else
				cout << X+1 << endl;
		}
	}
}