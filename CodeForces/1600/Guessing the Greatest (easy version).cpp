#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	bool right;
	int l=1, r=n, req, res;
	cout << "? " << l << " " << r << endl;
	cin >> req;
	
	if (req == l) {
		l++;
		right = true;
	} else if (req == r) {
		r--;
		right = false;
	} else {
		cout << "? " << req << " " << r << endl;
		cin >> res;
		
		if (req == res) {
			l = req;
			right = true;
		} else {
			r = req;
			right = false;
		}
	}
	
	while(l + 1 < r) {
		int mid = l+(r-l)/2;
		
		if (right)
			cout << "? " << req << " " << mid << endl;
		else 
			cout << "? " << mid << " " << req << endl;
			
		cin >> res;
			
		if (res == req) {
			if (right)
				r = mid;
			else
				l = mid;
		} else {
			if (right)
				l = mid;
			else
				r = mid;
		}
	}
	
	if (right)
		cout << "! " << r << endl;
	else 
		cout << "! " << l << endl;
}