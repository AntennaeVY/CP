#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testCases;
	cin >> testCases;
	
	for(int j = 1; j <= testCases; ++j)
	{
		vector<string> deck(52);
		for(int i = 0; i < 52; ++i)
			cin >> deck[i];
		cout << "Case " << j << ": " << deck[32] << endl;
	}
	return 0;
}