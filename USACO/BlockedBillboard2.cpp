#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;
};

struct Rectangle {
  Point lower_left, upper_right;
  int width, height;

  int getArea() { return width * height; }
};

int main() {
  ifstream fin("billboard.in");
  ofstream fout("billboard.out");

  Rectangle lawn, cow;
  fin >> lawn.lower_left.x >> lawn.lower_left.y;
  fin >> lawn.upper_right.x >> lawn.upper_right.y;
  fin >> cow.lower_left.x >> cow.lower_left.y;
  fin >> cow.upper_right.x >> cow.upper_right.y;
  
  lawn.width = abs(lawn.upper_right.x - lawn.lower_left.x);
  lawn.height = abs(lawn.upper_right.y - lawn.lower_left.y);

  int distX = min(lawn.upper_right.x, cow.upper_right.x) -
              max(lawn.lower_left.x, cow.lower_left.x);

  int distY = min(lawn.upper_right.y, cow.upper_right.y) -
              max(lawn.lower_left.y, cow.lower_left.y);

  if (lawn.lower_left.x >= cow.lower_left.x && lawn.upper_right.x <= cow.upper_right.x && (lawn.upper_right.y >= cow.lower_left.y && lawn.upper_right.y <= cow.upper_right.y || lawn.lower_left.y <= cow.upper_right.y && lawn.lower_left.y >= cow.lower_left.y )) {
    lawn.height -= distY;
  } 
  
  if (lawn.lower_left.y >= cow.lower_left.y && lawn.upper_right.y <= cow.upper_right.y && (lawn.lower_left.x >= cow.lower_left.x && lawn.lower_left.x <= cow.upper_right.x || lawn.upper_right.x >= cow.lower_left.x && lawn.upper_right.x <= cow.upper_right.x)) {
    lawn.width -= distX;
  }


  fout << lawn.getArea();
  return 0;
}