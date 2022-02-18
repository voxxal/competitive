# Blocked Billboard
~~My solution fails on test case 3 and 10, no idea why.~~

usaco.guide solution is a lot better
Notes:
 - use struct to simplify data.
 - uses varables to prevent messy code
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Rect {
  int x1, y1, x2, y2;
  int area() { return (y2 - y1) * (x2 - x1); }
};

int intersect(Rect p, Rect q) {
  int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
  int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
  return xOverlap * yOverlap;
}

int main() {
  fstream input("billboard.in");
  ofstream output("billboard.out");

  Rect a, b, t; // billboards a, b, and the truck
  input >> a.x1 >> a.y1 >> a.x2 >> a.y2;
  input >> b.x1 >> b.y1 >> b.x2 >> b.y2;
  input >> t.x1 >> t.y1 >> t.x2 >> t.y2;
  output << a.area() + b.area() - intersect(a, t) - intersect(b, t) << endl;
}
```

EDIT code fixed:
its because if any of the values in the `inter_area` are negitive they aren't intersecting, so you have to run `max(0, v)` there and not outside.