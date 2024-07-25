#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    
    int a = 0, b = 0;
	
	for(int j=0; j < 100; j++) {
		if (a > x)
			a--;
		else if (a < x)
			a++;
		
		if (b > y)
			b--;
		else if (b < y)
			b++;
			
		if (a == x && b == y)
			break;
			
		y--;
	}
	
	cout << (a == x && b == y ? "YES" : "NO") << endl;
  }
}