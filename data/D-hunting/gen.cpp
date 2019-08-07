#include <bits/stdc++.h>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
typedef long long ll;
const int inf = 2147483647;

int main() {
  int T = 4;
  printf("%d\n", T);
  //for (int i = 1; i <= 6; i++) 
    //for (int j = 1; j <= 6; j++) printf("%d %d\n", i, j);
  
  //for (int i = 0; i < 2; i++)
    //for (int j = 0; j < 2; j++) printf("%d %d\n", 500 - i, 500 - j);
  //T -= 36 * 2;
  for (int i = 0; i < T; i++) 
    printf("%d %d\n", rand() % 500 + 1, rand() % 500 + 1);
  return 0;
}
