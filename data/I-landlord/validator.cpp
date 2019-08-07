#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 10000, "T"); inf.readEoln();
    for (int t = 1; t <= T; t++) {
        for (int e = 0; e < 2; e++) {
            int x1 = inf.readInt(0, 1000000000, "x1"); inf.readSpace();
            int y1 = inf.readInt(0, 1000000000, "y1"); inf.readSpace();
            int x2 = inf.readInt(0, 1000000000, "x2"); inf.readSpace();
            int y2 = inf.readInt(0, 1000000000, "y2"); inf.readEoln();
            ensure(x1 < x2 && y1 < y2);
        }
    }
    inf.readEof();
    return 0;
}
