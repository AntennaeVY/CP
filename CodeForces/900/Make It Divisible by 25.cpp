#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		string n;
		cin >> n;
		
		
		int mn_5 = 100, mn_0 = 100;
		
		for(int i=n.size()-1; i >= 0; i--) {
			int cnt_5, cnt_0;
			
			if (n[i] == '5') {
				cnt_5 = n.size()-1-i;
				
				for(int j=i-1; j >= 0; j--) {
					if (n[j] == '2' || n[j] == '7')
						mn_5 = min(mn_5, cnt_5 + i-j-1);
				}
			} else if (n[i] == '0') {
				cnt_0 = n.size()-1-i;
				
				for(int j=i-1; j >= 0; j--) {
					if (n[j] == '0' || n[j] == '5')
						mn_0 = min(mn_0, cnt_0 + i-j-1);
				}
			}
		}
		
		cout << min(mn_5, mn_0) << endl;
	}
}