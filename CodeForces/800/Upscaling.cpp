#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<vector<char>> m(2*n, vector<char>(2*n, '.'));
		
		bool hashtag = true;
		
		for(int i=0; i < 2*n; i+=2) {
			hashtag = (i % 4 == 0);
			for(int j=0; j < 2*n; j+=2) {
				if (!hashtag) {
					hashtag = true;
					continue;
				}
				
				m[i][j] = m[i+1][j] = m[i][j+1] = m[i+1][j+1] = '#';
				hashtag = false;
			}
		}
		
		for(int i=0; i < 2*n; i++) {
			for(int j=0; j < 2*n; j++) {
				cout << m[i][j];
			}
			cout << endl;
		}
	}
}