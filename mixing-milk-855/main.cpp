#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Bucket {
    int capacity, amount;
};

void fill(Bucket &start, Bucket &other) {
    int milk_transfered = min(start.amount, other.capacity - other.amount);
    start.amount -= milk_transfered;
    other.amount += milk_transfered;
};

int main() {
    fstream input("mixmilk.in");
    ofstream output("mixmilk.out");

    Bucket buckets[3];
    input >> buckets[0].capacity >> buckets[0].amount;
    input >> buckets[1].capacity >> buckets[1].amount;
    input >> buckets[2].capacity >> buckets[2].amount;

    for(int i = 0; i < 100; i++) {
        fill(buckets[i % 3], buckets[(i + 1) % 3]);
    }
    output << buckets[0].amount << "\n" << buckets[1].amount << "\n" << buckets[2].amount;
}