/*
	Cracking the Code Interview
	
	Problem 1.2 - Check Permutation: 
		- Given two strings, write a method to decide if one
		  is a permutation of the other. 
*/

#include<bits/stdc++.h>
using namespace std;

map<char, int> make_count(string &s) {
	map<char, int> count;

	for(char ch : s)
		count[ch]++;
		
	return count;
}

bool has_same_characters(map<char,int> &m1, map<char,int> &m2) {
	bool ok = true;
		
	for(auto [ch, c] : m1) {
		if (m2[ch] != c) {
			ok = false;
		}
	}
	
	return ok;
}

bool is_permutation(string &s1, string &s2) {
	int n = s1.size();
	int m = s2.size();
	
	if (n != m) {
		return false;
	}
	
	map<char, int> count_s1 = make_count(s1);
	map<char, int> count_s2 = make_count(s2);

	return has_same_characters(count_s1, count_s2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s1, s2;
	cin >> s1 >> s2;
	
	cout << (is_permutation(s1, s2) ? "YES\n" : "NO\n");
}