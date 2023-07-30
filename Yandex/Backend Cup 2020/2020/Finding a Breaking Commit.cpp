#include<bits/stdc++.h>
using namespace std;

bool good(int mid) {
	cout << mid << endl;
	
	bool isGood;
	cin >> isGood;
	
	return isGood;
}

int main() {
	int n;
	cin >> n;
	
	int l=0, r=n;
	
	while(l+1 < r) {
		int mid = l+(r-l)/2;
		
		if (good(mid))
			l=mid;
		else 
			r=mid;
	}
	
	cout << "! " << r << endl;
}