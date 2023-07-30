#include<bits/stdc++.h>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	
	vector<int> cards(n);
	for(auto &ci:cards) cin >> ci;
	
	int petya = 0, vasya = 0;
	
	for(int i=0; i < n; i++) {
		if (cards[i]%15 == 0)
			continue;
			
		if (cards[i]%3 == 0)
			petya++;
		else if (cards[i]%5 == 0)
			vasya++;
			
		if (petya == k) {
			cout << "Petya" << endl;
			return 0;
		} else if (vasya == k) {
			cout << "Vasya" << endl;
			return 0;
		}
	}
	
	if (petya > vasya) {
		cout << "Petya" << endl;
	} else if (vasya > petya) {
		cout << "Vasya" << endl;
	} else {
		cout << "Draw" << endl;
	}
}