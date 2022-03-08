#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
    fstream input("cowsignal.in");
    ofstream output("cowsignal.out");
    
    int height, width, scale;
    input >> height >> width >> scale;

    for(int i = 0; i < height; i++) {
        string line, ret_line;
        input >> line;


        for(char c: line) {
            ret_line.append(string(scale, c));
        }

        for(int j = 0; j < scale; j++)
            output << ret_line + "\n";
    }
}