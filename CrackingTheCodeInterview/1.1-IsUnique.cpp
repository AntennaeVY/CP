/*
	Cracking the Code Interview
	
	Problem 1.1 - Is Unique: 
	 - Implement an algorithm to determine if a string has all 
	   unique characters. What if you cannot use additional 
	   data structures?
*/


#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	int n = s.size();
	bool is_unique = true;
	
	for(int i=0; i < n; i++) {
		for(int j=i+1; j < n; j++) {
			if (s[i] == s[j])
				is_unique = false;
		}
	}
	
	cout << (is_unique ? "YES" : "NO") << endl; 
}