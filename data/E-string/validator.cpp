#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 10, "T"); inf.readEoln();
    int totn = 0;
    for (int t = 1; t <= T; t++) {
        inf.readInt(1, 20, "k"); inf.readEoln();
        string str = inf.readToken("[a-z]{1,300000}"); inf.readEoln();
        totn += str.size();
    }
    inf.readEof();
    assert(totn <= 1000000);
    fprintf(stderr, "Total n: %d\n", totn);
    return 0;
}
