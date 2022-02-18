#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
using namespace std;

struct Rect {
  int x1, y1, x2, y2;
  int area() { return (y2 - y1) * (x2 - x1); }
};

int main() {
  fstream input("square.in");
  ofstream output("square.out");

  Rect a, b;
  input >> a.x1 >> a.y1 >> a.x2 >> a.y2;
  input >> b.x1 >> b.y1 >> b.x2 >> b.y2;
  
  output << pow(max(max({a.x1, a.x2, b.x1, b.x2}) - min({a.x1, a.x2, b.x1, b.x2}),
      max({a.y1, a.y2, b.y1, b.y2}) - min({a.y1, a.y2, b.y1, b.y2})), 2);
}