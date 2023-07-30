#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	
	while(t--) {
		string a,b;
		cin >> a >> b;
		
		int xa = 0, xb = 0;
		
		for(int i=0; i < a.size(); i++) {
			if (a[i] == 'X')
				xa++;
			else
				break;
		}
		
		
		for(int i=0; i < b.size(); i++) {
			if (b[i] == 'X')
				xb++;
			else
				break;
		}
		
		if (a.back() < b.back())
			cout << ">" << endl;
		else if (a.back() > b.back())
			cout << "<" << endl;
		else if (a.back() == 'L' && xa > xb) {
			cout << ">" << endl;
		} else if (a.back() == 'L' && xa < xb) {
			cout << "<" << endl;
		} else if (a.back() == 'S' && xa > xb){
			cout << "<" << endl;
		} else if (a.back() == 'S' && xa < xb) {
			cout << ">" << endl;
		} else {
			cout << "=" << endl;
		}
		
		
	}
}