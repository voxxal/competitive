#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    fstream input("paint.in");
    ofstream output("paint.out");
    int a, b, c, d; input >> a >> b >> c >> d;
    int raw = (b - a) + (d - c);
    int intersection = max(min(b, d) - max(a, c), 0);
    output << raw - intersection;
}