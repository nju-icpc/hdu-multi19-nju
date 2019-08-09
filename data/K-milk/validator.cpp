#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 25, "T"); inf.readEoln();
    int totn = 0;
    for (int t = 1; t <= T; t++) {
        int n = inf.readInt(1, 1000000, "n"); inf.readEoln(); totn += n;
        for (int i = 0; i < n; i++) {
            int a = inf.readInt(0, 1000000000, "a"); inf.readSpace();
            int b = inf.readInt(0, 1000000000, "b"); inf.readEoln(); 
        }
    }
    inf.readEof();
    ensure(totn <= 6000000);
    fprintf(stderr, "Total n: %d\n", totn);
    return 0;
}
