#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int q = inf.readInt(1, 1500, "q"); inf.readEoln();
    for (int i = 0; i < q; i++) {
        inf.readInt(1, 9, "d"); inf.readSpace();
        inf.readLong(0ll, 1000000000000000000, "x"); inf.readEoln();
    }
    inf.readEof();
    return 0;
}
