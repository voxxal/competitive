#include <bits/stdc++.h>
#include <fstream>
#include <utility>
using namespace std;

typedef pair<int, int> point;

int tarp_area(pair<point, point> a, pair<point, point> b) {
  int x_inter =  max(0, (min(a.second.first, b.second.first) - max(a.first.first, b.first.first)));
  int y_inter =  max(0, (min(a.second.second, b.second.second) - max(a.first.second, b.first.second)));
  
  if (x_inter == a.second.first - a.first.first && y_inter == a.second.second - a.first.second) {
    return 0;
  } else if(x_inter == a.second.first - a.first.first) { 
    return x_inter * (a.second.second - a.first.second - y_inter);
  } else if(y_inter == a.second.second - a.first.second) {  
    return (a.second.first - a.first.first - x_inter) * y_inter;
  } else {
    return (a.second.first - a.first.first) * (a.second.second - a.first.second);
  }
}

int main() {
  fstream input("billboard.in");
  ofstream output("billboard.out");
  pair<point, point> a;
  pair<point, point> b;
  input >> a.first.first >> a.first.second >> a.second.first >> a.second.second;
  input >> b.first.first >> b.first.second >> b.second.first >> b.second.second;
  
  output << tarp_area(a, b); 
} 
