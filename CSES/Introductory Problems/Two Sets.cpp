#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	
	if (n*(n+1) % 4) {
		cout << "NO" << endl;
		return 0;
	}
	
	
	vector<int> s1, s2;
	
	cout << "YES" << endl;
	
	if (n % 2 == 0) {
		
		for(int i=1; i <= n/2; i++) {
			if (i % 2) {
				s1.push_back(i);
				s1.push_back(n-i+1);
			}
			else {
				s2.push_back(i);
				s2.push_back(n-i+1);
			}
		}
		
	} else {
		
		for(int i=1; i <= (n-1)/2; i++) {
			if (i % 2) {
				s1.push_back(i);
				s1.push_back(n-i);
			}
			else {
				s2.push_back(i);
				s2.push_back(n-i);
			}
		}
		
		if ((n-1)/2 % 2)
			s2.push_back(n);
		else
			s1.push_back(n);
	} 
	
	
	cout << s1.size() << endl;
	for(auto &si : s1) cout << si << " ";
	cout << endl;
	
	cout << s2.size() << endl;
	for(auto &si : s2) cout << si << " ";
	cout << endl;
}