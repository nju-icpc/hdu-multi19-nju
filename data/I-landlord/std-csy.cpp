#include <bits/stdc++.h>
using namespace std;

vector<int> xs, ys;
vector<int> x, y;
           // x1  x2   y
vector<tuple<int, int, int>> hline;
           // x   y1   y2
vector<tuple<int, int, int>> vline;

bool testh(int x1, int x2, int y) {
    if (x1 > x2) swap(x1, x2);
    for (auto e : vline) {
        int x, y1, y2; tie(x, y1, y2) = e;
        if (y1 > y2) swap(y1, y2);
        if (x1 <= x and x <= x2 and y1 <= y and y <= y2) return false;
    }
    return true;
}

bool testv(int x, int y1, int y2) {
    if (y1 > y2) swap(y1, y2);
    for (auto e : hline) {
        int x1, x2, y; tie(x1, x2, y) = e;
        if (x1 > x2) swap(x1, x2);
        if (x1 <= x and x <= x2 and y1 <= y and y <= y2) return false;
    }
    return true;
}

int fa[32];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(int u, int v) {
    fa[find(u)] = find(v);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        xs.clear(); ys.clear();
        x.clear(); y.clear();
        hline.clear(); vline.clear();
        for (int i = 0; i < 2; i++) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1 <<= 1; y1 <<= 1; x2 <<= 1; y2 <<= 1;
            xs.push_back(x1); xs.push_back(x2);
            ys.push_back(y1); ys.push_back(y2);
            hline.emplace_back(x1, x2, y1);
            hline.emplace_back(x1, x2, y2);
            vline.emplace_back(x1, y1, y2);
            vline.emplace_back(x2, y1, y2);
        }

        sort(xs.begin(), xs.end()); 
        xs.erase(unique(xs.begin(), xs.end()), xs.end()); 
        sort(ys.begin(), ys.end()); 
        ys.erase(unique(ys.begin(), ys.end()), ys.end()); 

        x.push_back(xs.front() - 1);
        for (int i = 1; i < xs.size(); i++) x.push_back((0u + xs[i] + xs[i-1]) / 2);
        x.push_back(xs.back() + 1);
        
        y.push_back(ys.front() - 1);
        for (int i = 1; i < ys.size(); i++) y.push_back((0u + ys[i] + ys[i-1]) / 2);
        y.push_back(ys.back() + 1);

        int nx = x.size(), ny = y.size();
        iota(fa, fa + nx * ny, 0);
        for (int i = 0; i < nx; i++) for (int j = 0; j < ny; j++) {
            if (i and testh(x[i-1], x[i], y[j])) unite(i*ny+j, (i-1)*ny+j);
            if (j and testv(x[i], y[j-1], y[j])) unite(i*ny+j, i*ny+j-1);
        }
        int ans = 0;
        for (int i = 0; i < nx * ny; i++) ans += int(fa[i] == i);
        printf("%d\n", ans);
    }
    return 0;
}
