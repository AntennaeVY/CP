#include<bits/stdc++.h>
using namespace std;

int grid[9][9];
int dir[4][2] = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

int search(int i, int j, int pos, string &s) {	 
	if (grid[i][j])
		return 0;
		
	if (i == 7 && j == 1)
		return (int)(pos == 48);
		
	if (pos == 48)
		return (int)(i == 7 && j == 1);

	if (
		(grid[i+1][j] && grid[i-1][j]) && 
		(!grid[i][j+1] && !grid[i][j-1])
	)
		return 0;
	
	if (
		(grid[i][j+1] && grid[i][j-1]) &&
		(!grid[i+1][j] && !grid[i-1][j])
	)
		return 0;
		
	grid[i][j] = true;
	
	int cnt = 0;
	
	if (s[pos] == '4')
		for(int c : {0, 1, 2, 3})
			cnt += search(i + dir[c][0], j + dir[c][1], pos+1, s);
	else
		cnt += search(i + dir[s[pos] - 48][0], j + dir[s[pos] - 48][1], pos+1, s);

	grid[i][j] = false;
	return cnt;
}

int main() {
	string s;
	cin >> s;

	for(int i=1; i <= 7; i++) {
		grid[0][i] = true;
		grid[8][i] = true;
		
		grid[i][0] = true;
		grid[i][8] = true;
	}
	
	for(int i=0; i < 48; i++) {
		if (s[i] == 'U')
			s[i] = '0';
		else if (s[i] == 'D')
			s[i] = '1';
		else if (s[i] == 'L')
			s[i] = '2';
		else if (s[i] == 'R')
			s[i] = '3';
		else
			s[i] = '4';
	}
	
	cout << search(1, 1, 0, s);
}	