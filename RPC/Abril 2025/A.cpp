#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int r, c;
	cin >> r >> c;
	
	int cnt = 0;
	
	for(int i=0; i < r; i++) {
		string s;
		cin >> s;
		
		int d = c - s.size();
		
		string p(d/2, '.');
		string q(d - d/2, '.');
		
		if (d % 2 == 0) {
			cout << p << s << q << endl;
		} else {
			if (cnt % 2 == 0) {
				if (p.size() > q.size())
					swap(p,q);
				
				cout << p << s << q << endl;
			} else {
				if (p.size() < q.size())
					swap(p,q);
				
				cout << p << s << q << endl;
			}
			
			cnt++;
		}
	}
}