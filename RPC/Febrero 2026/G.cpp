#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;

	getline(cin, s);
	cin.ignore();
	
	int ans = 0;
	
	if (s.starts_with("Animal"))
		ans = 1;
	else if (s.starts_with("Social"))
		ans = 2;
	else if (s.starts_with("Single"))
		ans = 4;
	else if (s.starts_with("Cover"))
		ans = 5;
	else if (s.starts_with("Country"))
		ans = 6;
	else if (s.starts_with("Forgotten"))	
		ans = 8;
	else if (s.starts_with("Grimms"))	
		ans = 10;
	else if (s.starts_with("Who"))	
		ans = 11;
	else if (s.starts_with("World"))	
		ans = 13;
	else if (s.starts_with("Jaded"))	
		ans = 15;
	else if (s.starts_with("Knavish"))	
		ans = 17;
	else if (s.starts_with("What"))	
		ans = 19;
	else if (s.starts_with("Picture"))	
		ans = 21;
	else
		assert(false);
		
	cout << ans << endl;
}