#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 4, "T"); inf.readEoln();
    for (int t = 1; t <= T; t++) {
        int n = inf.readInt(1, 300000, "n"); inf.readSpace();
        int m = inf.readInt(1, 300000, "m"); inf.readEoln();
        for (int i = 1; i < n; i++) {
            inf.readInt(1, i, "f");
            if (i == n - 1) inf.readEoln(); else inf.readSpace();
        }
        for (int i = 0; i < m; i++) {
            int op = inf.readInt(1, 2, "op"); inf.readSpace();
            if (op == 1) {
                inf.readInt(1, n, "a"); inf.readSpace();
                int x = inf.readInt(1, n, "x"); inf.readSpace();
                inf.readInt(0, x - 1, "y"); inf.readSpace();
                inf.readInt(0, 500, "z"); inf.readEoln();
            } else {
                inf.readInt(1, n, "a"); inf.readEoln();
            }
        }
    }
    inf.readEof();
    return 0;
}
