#include <array>
#include <bits/stdc++.h>

using namespace std;

void countFreq (const string &s, array<int, 26> &freq) {
	for (char c: s) {
		freq[c - 'a']++;
	}
}

int main () {
    fstream  fin  ("blocks.in" );
    ofstream fout ("blocks.out");
    int boards;
    array<int, 26> letters{};
    fin >> boards;
    for (int i = 0; i < boards; i++) {
        array<int, 26> oneFreq{}, twoFreq{};
        string one,   two;
        fin >> one >> two;
        countFreq(one, oneFreq);
        countFreq(two, twoFreq);
        for(int j = 0; j < 26; j++) {
            letters[j] += max(oneFreq[j], twoFreq[j]);
        }
    }
    for (int i = 0; i < 26; i++)
        fout << letters[i] << "\n";
}