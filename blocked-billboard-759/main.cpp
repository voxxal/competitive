#include <bits/stdc++.h>
#include <fstream>
#include <utility>
using namespace std;

typedef pair<int, int> point;

int inter_area(pair<point, point> a, pair<point, point> b) {
  return (max(0, (min(a.second.first, b.second.first) -
           max(a.first.first, b.first.first))) *
          max(0, (min(a.second.second, b.second.second) -
           max(a.first.second, b.first.second))));
}

int main() {
  fstream input("billboard.in");
  ofstream output("billboard.out");
  pair<point, point> boards[3] = {};
  for (int i = 0; i < 3; i++) {
    int a, b, c, d;
    input >> a >> b >> c >> d;
    boards[i] = {{a, b}, {c, d}};
  }
  int total_area = (boards[0].second.first - boards[0].first.first) *
                       (boards[0].second.second - boards[0].first.second) +
                   (boards[1].second.first - boards[1].first.first) *
                       (boards[1].second.second - boards[1].first.second);
  total_area -= inter_area(boards[0], boards[2]);
  total_area -= inter_area(boards[1], boards[2]);
  output << total_area;
}