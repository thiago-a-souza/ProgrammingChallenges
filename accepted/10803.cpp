/* Thunder Mountain - 27/06/2007 */
#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

#define MAX 105
#define INF 3200000

double adj[MAX][MAX];

void floyd(int n){
register int i, j, k;

	for(k=0; k<n; k++)
	   for(i=0; i<n; i++)
	      for(j=0; j<n; j++)
	         if(adj[i][k]+adj[k][j] < adj[i][j])
	            adj[i][j] = adj[i][k] + adj[k][j];
}

void clearBuffer(int n){
register int i, j;

	for(i=0; i<n; i++){
	   for(j=0; j<n; j++)
	      adj[i][j] = INF; 
	   adj[i][i] = 0;
	}
}

void show(int n){
int i, j;
	
	for(i=0; i<n; i++){
	   for(j=0; j<n; j++)
	      cout << adj[i][j] << " ";
	   cout << endl;
	}
	cout << "-------------\n";
}

main(){
register int i, j, k;
int tests, n;
int x[MAX], y[MAX];
double dist, maior;

	cin >> tests;
	for(i=0; i<tests; i++){
	     
	   cin >> n;
	   clearBuffer(n);
	   for(j=0; j<n; j++)
	      cin >> x[j] >> y[j];
	   for(j=0; j<n-1; j++)
	      for(k=0; k<n; k++){
	         dist = sqrt((x[j]-x[k])*(x[j]-x[k]) + (y[j]-y[k])*(y[j]-y[k]));
	         if(dist <= 10){
	           adj[j][k] = dist;
	           adj[k][j] = dist;
	         }
	      }
	   floyd(n);
	   maior = -1;
	   for(j=0; j<n; j++)
	      for(k=0; k<n; k++)
	         if(adj[j][k]>maior)
	           maior = adj[j][k];
	   printf("Case #%d:\n",i+1);
	   if(maior>=INF)
	     cout << "Send Kurdy\n";
	   else{
	       maior = maior*10000.0 + 0.5;
	       maior = floor(maior)/10000.0;
	       printf("%.4lf\n",maior);
	   }
	   cout << endl;  
	}
}

