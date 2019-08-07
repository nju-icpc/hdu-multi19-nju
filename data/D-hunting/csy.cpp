#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[94m%s " fmt "\n\033[0m", \
  __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif
 
#define rep(i, n) for (int i=0; i<(n); i++)
#define Rep(i, n) for (int i=1; i<=(n); i++)
#define range(x) (x).begin(), (x).end()
typedef long long LL;
typedef unsigned long long ULL;
 
pair<int, int> 
pat3[6] = {
  {0, 0}, {1, 1}, {2, 0}, {0, 1}, {2, 1}, {1, 0}
},
pat4[8] = {
  {0, 0}, {1, 1}, {3, 1}, {2, 0}, {0, 1}, {1, 0}, {3, 0}, {2, 1}
}, 
pat5[10] = {
  {0, 0}, {1, 1}, {3, 1}, {1, 0}, {0, 1}, {2, 1}, {4, 0}, {2, 0}, {4, 1}, {3, 0}
},
patr3[6] = {
  {0, 0}, {1, 2}, {0, 1}, {1, 0}, {0, 2}, {1, 1}
},
pat9[9] = {
  {0, 0}, {2, 1}, {1, 0}, {0, 1}, {2, 2}, {0, 2}, {1, 1}, {2, 0}, {1, 2}
};
 
int rev;
int m, n;
 
inline void writepat(pair<int, int> pat[], int sz, int offx, int offy, int rx) {
  _debug("sz=%d, offx=%d, offy=%d, rx=%d", sz, offx, offy, rx);
  for (int i=0; i<sz; i++) {
    int xx, yy;
    tie(yy, xx) = pat[i];
    xx += offx + 1; yy += offy + 1;
    if (rx) yy = m + 1 - yy;
    if (rev) swap(xx, yy);
    printf("%d %d\n", xx, yy);
  }
}
 
int main() {
  int T;
  cin >> T ;
  while (T--) {
    cin >> n >> m;
    if (m == 2) swap(n, m), rev = 1;
    else rev = 0;
    if (m == 1 && n == 1) {
      printf("YES\n");
      printf("1 1\n"); 
    } else if (m == 1 || n == 1){
      printf("NO\n");
    } else if (n == 2 && m == 2) {
      printf("NO\n");
    } else {
      printf("YES\n");
      int flag = 0;
      for (int i=0; i<n; i+=2) {
        if (n - i == 3) {
          for (int j=0; j<m; j+= 2) {
            if (m - j == 3) {
              _debug("pat9");
              writepat(pat9, 9, i, j, flag);
              break;
            } else {
              _debug("patr3");
              writepat(patr3, 6,  i, j, flag);
            }
          }
          break;
        } else {
          for (int j=0; j<m; j+=3) {
            if (m - j == 4) {
              _debug("pat4");
              writepat(pat4, 8,  i, j, flag);
              break;
            } else if (m - j == 5) {
            _debug("pat5");
              writepat(pat5, 10, i, j, flag);
              break;
            } else {
              _debug("pat3");
              writepat(pat3, 6, i, j, flag);
            }
          }
        }
        flag = 1^flag;
      } 
    }
  }
  return 0;
}
/**************************************************************
    Problem: 1501
    User: tg_03
    Language: C++
    Result: Accepted
    Time:252 ms
    Memory:1548 kb
****************************************************************/
