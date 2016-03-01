/* Connect the Campus  -  07/11/2007 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

#define MAX_A 700000
#define MAX_V 800
#define debug(x)

using namespace std;

typedef struct {
int u, v;
double w;
} TAdj;

typedef struct{
int x, y;
} TPoint;

TAdj adj[MAX_A];
int n_edges, n_vert;
double total;
int p[MAX_V];

int cmp(const void *a, const void *b){
TAdj *x, *y;

	x = (TAdj*)a;
	y = (TAdj*)b;
	if(x->w < y->w)
	  return -1;
	if(x->w > y->w)
	  return 1;
	return 0;

}

int findSet(int x){

	if(x != p[x])
	  p[x] = findSet(p[x]);
	return p[x];

}

void kruskal(){
int u, v, u_set, v_set;

	for(int i=0; i<n_vert; i++)
	   p[i] = i;

	qsort(adj, n_edges, sizeof(TAdj), cmp);

	for(int i=0; i<n_edges; i++){
	   u = adj[i].u; v = adj[i].v;
	   u_set = findSet(u);
	   v_set = findSet(v);
	   if(u_set != v_set){
	     if(u_set < v_set)
		p[v_set] = p[u_set];
	     else
		p[u_set] = p[v_set];
	     total += adj[i].w;
	   }
	}

}

main(){
int m, x, y;
TPoint points[MAX_V];
double mAdj[MAX_V][MAX_V];

	while(scanf("%d",&n_vert) == 1){
	     for(int i = 0; i < n_vert; i++)
	        scanf("%d %d",&points[i].x, &points[i].y);
	     for(int i = 0; i < n_vert; i++)
		for(int j = 0; j < n_vert; j++)
		   mAdj[i][j] = 0.0;

	     for(int i = 0; i < n_vert - 1; i++)
		for(int j = i + 1; j < n_vert; j++)
		   mAdj[i][j] = sqrt((points[i].x - points[j].x)*(points[i].x - points[j].x)+
				     (points[i].y - points[j].y)*(points[i].y - points[j].y));

debug(for(int i=0; i<n-1; i++){ for(int j=i+1; j<n; j++) cout << mAdj[i][j] << " "; cout << endl;}
cout << "---------------\n";)


	     scanf("%d",&m);

	     for(int i=0; i<m; i++){
		scanf("%d %d",&x, &y);
                if(x < y)
		   mAdj[x-1][y-1] = 0.0;
		else
		   mAdj[y-1][x-1] = 0.0;
	     }

debug(for(int i=0; i<n-1; i++){ for(int j=i+1; j<n; j++) cout << mAdj[i][j] << " "; cout << endl;})

	     n_edges = 0;
	     for(int i = 0; i < n_vert - 1; i++)
		for(int j = i + 1; j < n_vert; j++){
		   adj[n_edges].u = i; adj[n_edges].v = j;
		   adj[n_edges++].w = mAdj[i][j];
		}
	     total = 0.0;
             kruskal();
             printf("%.2lf\n",total);
		
		   
	}	


}
