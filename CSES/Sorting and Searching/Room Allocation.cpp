#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<pair<int, int>, int>> customers(n);
  vector<int> roomsOrder(n, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      rooms;
  int room{};

  for (int i{}; i < n; i++) {
    cin >> customers[i].first.first;
    cin >> customers[i].first.second;

    customers[i].second = i;
  }

  sort(customers.begin(), customers.end());

  for (int i{}; i < n; i++) {
    if (rooms.size() == 0) {
      roomsOrder[customers[i].second] = ++room;
      rooms.push(make_pair(customers[i].first.second, room));
    } else if (rooms.top().first < customers[i].first.first) {
      rooms.push(make_pair(customers[i].first.second, rooms.top().second));
      roomsOrder[customers[i].second] = rooms.top().second;

      rooms.pop();
    } else {
      roomsOrder[customers[i].second] = ++room;
      rooms.push(make_pair(customers[i].first.second, room));
    }
  }

  cout << room << endl;

  for (int i{}; i < n; i++) {
    cout << roomsOrder[i] << " ";
  }
}