#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 120, "T"); inf.readEoln();
    int totn = 0;
    for (int t = 1; t <= T; t++) {
        int n = inf.readInt(1, 100000, "n"); inf.readSpace(); totn += n;
        int d = inf.readInt(0, 9, "d"); inf.readEoln();
        set<string> names;
        set<int> times;
        for (int i = 0; i < n; i++) {
            string str = inf.readToken("[a-zA-Z]{1,10}"); inf.readSpace();
            int prob = inf.readInt(0, 1000000000, "p"); inf.readSpace();
            int penalty = inf.readInt(0, 1000000000, "t"); inf.readEoln();
            ensure(names.count(str) == 0 and times.count(penalty) == 0);
            names.insert(str); times.insert(penalty);
        }
    }
    inf.readEof();
    fprintf(stderr, "Total n: %d\n", totn);
    ensure(totn <= 1000000);
    return 0;
}
