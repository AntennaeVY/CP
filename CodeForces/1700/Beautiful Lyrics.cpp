#include<bits/stdc++.h>
using namespace std;

bool isVowel(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

int vowelCount(string &s) {
	int cnt = 0;
	for(char c : s)
		cnt += isVowel(c);
	
	return cnt;
}

int lastVowel(string &s) {
	for(int i=s.size(); i >= 0; i--) 
		if (isVowel(s[i]))
			return s[i];
}

int main() {
	int n;
	cin >> n;
	
	map<int, map<char, vector<string>>> all;
	
	for(int i=0; i < n; i++) {
		string s;
		cin >> s;
		
		all[vowelCount(s)][lastVowel(s)].push_back(s);
	}
	
	vector<pair<string, string>> comp, semi;
	
	for(auto &[_, m] : all) {
		vector<string> rem;
		
		for(auto &[_, v] : m) {
			while(v.size() >= 2) {
				string s1 = v.back(); v.pop_back();
				string s2 = v.back(); v.pop_back();
				
				comp.emplace_back(s1, s2);
			}
			
			if (!v.empty())
				rem.push_back(v.back());
				
			v.clear();
		}
		
		while(rem.size() >= 2) {
			string s1 = rem.back(); rem.pop_back();
			string s2 = rem.back(); rem.pop_back();
			
			semi.emplace_back(s1, s2);
		}
	}
	
	vector<pair<pair<string, string>, pair<string, string>>> ans;
	
	for(auto &s : semi) {
		if (comp.empty())
			break;
			
		auto t = comp.back(); comp.pop_back();
		ans.emplace_back(s, t);
	}
	
	while(comp.size() >= 2) {
		auto s1 = comp.back(); comp.pop_back();
		auto s2 = comp.back(); comp.pop_back();
		
		ans.emplace_back(s1, s2);
	}
	
	cout << ans.size() << endl;
	
	for(auto &[p1, p2] : ans) {
		cout << p1.first << " " << p2.first << endl;
		cout << p1.second << " " << p2.second << endl;
	}
}