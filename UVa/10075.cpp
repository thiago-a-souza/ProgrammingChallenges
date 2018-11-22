/* Airlines - 14/06/2007 */
#include<iostream>
#include<cmath>
#include<string>
#include<map>
#include<cstdio>

using namespace std;

#define RADIUS 6378
#define PI 3.141592653589793
#define INF 320000000.0
#define MAX 102

long double adj[MAX][MAX];

long double spherical_distance(long double p_lat, long double p_long, long double q_lat, long double q_long){

	return (acos(sin(p_lat)*sin(q_lat) +
	               cos(p_lat)*cos(q_lat)*cos(p_long)*cos(q_long) +
	               cos(p_lat)*cos(q_lat)*sin(p_long)*sin(q_long))*RADIUS);

}

void floyd(int n){
register int i, j, k;

	for(k=1; k<=n; k++)
	   for(i=1; i<=n; i++)
	      for(j=1; j<=n; j++)
	         if(adj[i][k] + adj[k][j] < adj[i][j])
	           adj[i][j] = adj[i][k] + adj[k][j];
}

void initialize(int n){
register int i, j;

	for(i=0; i<=n; i++){
	   for(j=0; j<=n; j++)
	      adj[i][j] = INF;
	   adj[i][i] = 0;
	}
}

main(){
register int i;
int n, m, q, cont, ct1, ct2, scenario=1;
long double lati[MAX], longi[MAX];
char str[25], city1[25], city2[25];
map<string,int> names;

	cin >> n >> m >> q;
	while(n!=0 && m!=0 && q!=0){
	     if(scenario>1)
	       cout << endl;
	     cont = 1;
	     initialize(n);
	     for(i=0; i<n; i++){
	        cin >> str >> lati[cont] >> longi[cont];
	        lati[cont]=(lati[cont]*PI)/180.0;
	        longi[cont]=(longi[cont]*PI)/180.0;
	        names[str]=cont++;
	     }
	     for(i=0; i<m; i++){
	        cin >> city1 >> city2;
	        ct1 = names[city1];
	        ct2 = names[city2];
	        if(ct1>0 && ct2>0){
	          adj[ct1][ct2] = spherical_distance(lati[ct1],longi[ct1],lati[ct2],longi[ct2]);
	          adj[ct1][ct2] = adj[ct1][ct2]+0.5; //arredondamento p/ ser AC
	          adj[ct1][ct2] = (int)adj[ct1][ct2];
	        }  
	     }
	     floyd(n);
	     cout << "Case #" << scenario << endl;
	     scenario++;
	     for(i=0; i<q; i++){
	        cin >> city1 >> city2;
	        ct1 = names[city1];
	        ct2 = names[city2];
	        if(ct1>0 && ct2>0){
	          if(adj[ct1][ct2]!=INF)
	            printf("%d km\n",(int)adj[ct1][ct2]);
	          else
	            cout << "no route exists\n";
	        }
	     }
	     names.clear();
	     cin >> n >> m >> q;
	}

}

