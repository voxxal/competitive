#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream input("speeding.in");
    ofstream output("speeding.out");

    int n, m;
    input >> n >> m;
    vector<int> speedLimits(100);
    vector<int> bessieSpeed(100);

    int currentDistance = 0;
    for (int i = 0; i < n; i++) {
        int a, b; input >> a >> b;
        for (int j = currentDistance; j < currentDistance + a; j++) {
            speedLimits[j] = b;
        }
        currentDistance += a;
    }

    currentDistance = 0;
    for (int i = 0; i < n; i++) {
        int a, b; input >> a >> b;
        for (int j = currentDistance; j < currentDistance + a; j++) {
            bessieSpeed[j] = b;
        }
        currentDistance += a;
    }

    int maxSpeed = 0;
    for (int i = 0; i < 100; i++) {
            maxSpeed = max(maxSpeed, bessieSpeed[i] - speedLimits[i]);
    }
    output << maxSpeed;
}