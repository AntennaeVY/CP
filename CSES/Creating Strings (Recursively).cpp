#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

set<string> permutations;
string permutation;
vector<bool> chosen;

void generate_permutations(string &s) {
	if (permutation.size() == s.size()) {
		permutations.insert(permutation);
		return;
	}
	
	for(int i=0; i < s.size(); i++) {
		if (chosen[i])
			continue;
			
		chosen[i] = true;
		permutation.push_back(s[i]);
		
		generate_permutations(s);
		
		chosen[i] = false;
		permutation.pop_back();
	}
}
	
int main() {
	string s;
	cin >> s;
	
	sort(s.begin(), s.end());
	
	for(int i=0; i < s.size(); i++) {
		chosen.push_back(false);
	}
	
	generate_permutations(s);
	
	cout << permutations.size() << endl;
	
	for(auto p : permutations) {
		cout << p << endl;
	}
}	