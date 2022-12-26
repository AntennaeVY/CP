#include<bits/stdc++.h>
using namespace std;

map<int, int> m;
vector<vector<int>> v(9, vector<int>(1e6+1, 0));

void precalculate() {
	for(int i=1; i <= 1e6; i++) {
		int num = i;
		
		while(num / 10 != 0) {
			if (m[num] != 0) {
				m[i] = m[num];
				break;
			}
			
			int num2 = num, cnt = 1;
			
			while(num2 != 0) {
				int dig = num2 % 10;
				num2 /= 10;
				
				if (dig != 0)
					cnt *= dig;
			}

			num = cnt;
		}
		
		if (m[i] == 0)
			m[i] = num;
		
		v[m[i]-1][i] += 1;
		
		for(int j=0; j < 9; j++) {
			v[j][i] += v[j][i-1];
		}  
	}
}

int main() {
	precalculate();
	
	int q;
	cin >> q;
	
	for(int i=0; i < q; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		
		cout << v[k-1][r] - v[k-1][l-1] << endl;
	}
}