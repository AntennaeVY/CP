#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
constexpr int MAX_N = 500;

int m, n;
int wy, wx;

vector<vector<int>> grid(MAX_N, vector<int>(MAX_N));
vector<vector<bool>> wp(MAX_N, vector<bool>(MAX_N));
vector<vector<bool>> mark(MAX_N, vector<bool>(MAX_N));

/** Floodfill all nodes that can be reached given a value of D */
void floodfill(int d) {
	queue<pair<int, int>> q;

	q.push(make_pair(wy, wx));
	mark[wy][wx] = 1;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];
			if (ny >= 0 && ny < m && nx >= 0 && nx < n) {
				/*
				 * if the target cell is not visited before
				 * and the elevation difference is within D
				 * push the cell into the queue
				 */
				if (!mark[ny][nx] &&
				    abs(grid[p.first][p.second] - grid[ny][nx]) <= d) {
					q.push(make_pair(ny, nx));
					mark[ny][nx] = true;
				}
			}
		}
	}
}

/** Checks if all waypoints are reachable within the given D */
bool reachable(int d) {
	// reset the grid that keeps the reachable points
	mark = vector<vector<bool>>(m, vector<bool>(n));

	floodfill(d);

	// check if there is any unreachable waypoints
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (wp[i][j] && !mark[i][j]) { return false; }
		}
	}
	return true;
}

int main() {
	freopen("ccski.in", "r", stdin);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) { cin >> grid[i][j]; }
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int is_waypoint;
			cin >> is_waypoint;
			wp[i][j] = is_waypoint != 0;
			// keep one of the waypoints as the starting point
			if (wp[i][j]) {
				wy = i;
				wx = j;
			}
		}
	}

	// binary search for the elevation difference
	int l = 0;
	int r = INT32_MAX;
	while (l < r) {
		int d = (l + r) / 2;
		if (reachable(d)) {
			r = d;
		} else {
			l = d + 1;
		}
	}

	freopen("ccski.out", "w", stdout);
	cout << l << endl;
}