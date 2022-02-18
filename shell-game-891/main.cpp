#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
    fstream input("shell.in");
    ofstream output("shell.out");
    int shells[3] = { 0, 0, 0 };
    int n; input >> n;
    for (int i = 0; i < n; i++) {
        int a, b, g;
        input >> a >> b >> g;
        swap(shells[a - 1], shells[b - 1]);
        shells[g - 1]++;
    }
    output << *max_element(shells, shells + 3);
}