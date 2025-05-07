#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int g, r;
	cin >> g >> r;
	
	int gr = min(g,r);
	int ans = 10*gr;
	
	g -= gr, r -= gr;
	
	ans += 10*(g/3), g %= 3;
	ans += 3*(g/2), g %= 2;
	ans += g;
	
	cout << ans << endl;
}