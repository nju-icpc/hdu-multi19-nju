#include<bits/stdc++.h>
#define N 200005
using namespace std;
map<int,int>ma[N];
int id[N];
struct pa {
	int x,y,v;
}edge[N],q[N];
inline void work1() {
	int n=100000,m=200000;
	int tot=0;
	for (int i=1;i<=n;i++) id[i]=i;
	random_shuffle(id+1,id+1+n);
	for (int i=2;i<=n;i++) edge[++tot]=pa{id[i-1],id[i],i};
	for (;tot<=m;) {
		int x=rand()%n+1,y=rand()%n+1;
		while (x==y) x=rand()%n+1,y=rand()%n+1;
		int t=rand()%1000000000+1;
		while (t<=n) t=rand()%1000000000+1; 
		edge[++tot]=pa{x,y,t};
	}
	random_shuffle(edge+1,edge+1+tot);
	int Q=100000;
	printf("%d %d %d\n",n,m,Q);
	for (int i=1;i<=n;i++) ma[i].clear(),ma[i][i]=1;
	for (int i=1;i<=Q;i++) {
		int x=rand()%n+1,y=rand()%n+1;
		while (ma[x][y]) x=rand()%n+1,y=rand()%n+1;
		ma[x][y]=ma[y][x]=1;
		q[i]=pa{x,y,0};
	}
	for (int i=1;i<=m;i++) 
	printf("%d %d %d\n",edge[i].x,edge[i].y,edge[i].v);
	for (int i=1;i<=Q;i++) 
	printf("%d %d\n",q[i].x,q[i].y);
}
inline void work2() {
	int n=100000,m=200000;
	int tot=0;
	for (;tot<=m;) {
		int x=rand()%n+1,y=rand()%n+1;
		while (x==y) x=rand()%n+1,y=rand()%n+1;
		int t=rand()%1000000000+1;
		edge[++tot]=pa{x,y,t};
	}
	random_shuffle(edge+1,edge+1+tot);
	int Q=100000;
	printf("%d %d %d\n",n,m,Q);
	for (int i=1;i<=n;i++) ma[i].clear(),ma[i][i]=1;
	for (int i=1;i<=Q;i++) {
		int x=rand()%n+1,y=rand()%n+1;
		while (ma[x][y]) x=rand()%n+1,y=rand()%n+1;
		ma[x][y]=ma[y][x]=1;
		q[i]=pa{x,y,0};
	}
	for (int i=1;i<=m;i++) 
	printf("%d %d %d\n",edge[i].x,edge[i].y,edge[i].v);
	for (int i=1;i<=Q;i++) 
	printf("%d %d\n",q[i].x,q[i].y);
}
inline void work3() {
	int n=rand()%1000+1,m=rand()%1000+1;
	
	int tot=0;
	for (;tot<=m;) {
		int x=rand()%n+1,y=rand()%n+1;
		while (x==y) x=rand()%n+1,y=rand()%n+1;
		int t=rand()%1000000000+1;
		edge[++tot]=pa{x,y,t};
	}
	random_shuffle(edge+1,edge+1+tot);
	int Q=rand()%1000+1;;
	printf("%d %d %d\n",n,m,Q);
	fprintf(stderr,"%d %d %d\n",n,m,Q);
	for (int i=1;i<=n;i++) ma[i].clear(),ma[i][i]=1;
	for (int i=1;i<=Q;i++) {
		int x=rand()%n+1,y=rand()%n+1;
		while (ma[x][y]) x=rand()%n+1,y=rand()%n+1;
		ma[x][y]=ma[y][x]=1;
		q[i]=pa{x,y,0};
	}
	for (int i=1;i<=m;i++) 
	printf("%d %d %d\n",edge[i].x,edge[i].y,edge[i].v);
	for (int i=1;i<=Q;i++) 
	printf("%d %d\n",q[i].x,q[i].y);
}
int main() {
    srand(20190807);
	freopen("0.in","w",stdout);
	int test=5;
	printf("%d\n",test);
	work1();
	work2();
	for (int i=1;i<=3;i++) work3();
}
