#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> candies(n);
		for(auto &it:candies) cin >> it;
		
		int moves = 0, bob = n-1, alice = 0;
		int sum_alice = 0, sum_bob = 0, current_alice = 0, current_bob = 0;
		bool alice_turn = true;
		
		while(alice <= bob) {
			moves++;
			
			if (alice_turn) {
				current_alice = 0;
			
				while (alice <= bob && current_alice <= current_bob) {
					sum_alice += candies[alice];
					current_alice += candies[alice];
					alice++;
				}
				
				alice_turn = false;
			} else {
				current_bob = 0;
				
				while(alice <= bob && current_bob <= current_alice) {
					sum_bob += candies[bob];
					current_bob += candies[bob];
					bob--;
				}
				
				alice_turn = true;
			}
		}
		
		cout << moves << " " << sum_alice << " " << sum_bob << endl;
	}
}