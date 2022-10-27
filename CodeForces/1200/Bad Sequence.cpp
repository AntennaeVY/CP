#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int open = 0, closed = 0;
	stack<int> left;
	
	for(int i=0; i < s.size(); i++) {
		if (s[i] == '(') {
			open++;
			left.push(1);
		} else {
			closed++;
			
			if (!left.empty())
				left.pop();
		}
	}
	
	if (open != closed || left.size() > 1)
		cout << "No" << endl;
	else if (open == closed && left.size() <= 1)
		cout << "Yes" << endl;
}