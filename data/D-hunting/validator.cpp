#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 240, "T"); inf.readEoln();
    int totn = 0;
    for (int t = 1; t <= T; t++) {
        int n = inf.readInt(1, 100, "n"); inf.readSpace();
        int m = inf.readInt(1, 100, "m"); inf.readEoln();
        totn += n * m;
    }
    inf.readEof();
    fprintf(stderr, "Total size: %d\n", totn);
    return 0;
}
