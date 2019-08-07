#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 100000;
char s[maxn];
int main() {
	
//	freopen("a.ans", "w", stdout);
	
	int t = 2048;
	printf("%d %d\n", t * 4, t);
	
	int n = 2 * t;
	s[1] = 'a';
	for (int j = 1; j <= n; j *= 2) 
		for (int i = j + 1; i <= j + j; i++) 
			if (s[i - j] == 'a') s[i] = 'b';
			else s[i] = 'a';
	for (int i = 1; i <= n; i++) printf("%c", s[i]);
	
	for (int i = 1; i <= t; i++) printf("a");
//	puts("");
	printf("b");
	for (int i = 1; i < t; i++) printf("a");
//	puts("");
	
	puts("");
	return 0; 
}


