/* Meeting Prof. Miguel - 28/07/2007 */
#include<iostream>
#include<climits>
#include<cstdio>

using namespace std;

#define MAX 30
#define INF INT_MAX/2
#define LIM 26
void floyd(int adj[MAX][MAX]){
register int i, j, k;

	for(k=0; k<LIM; k++)
	   for(i=0; i<LIM; i++)
	      for(j=0; j<LIM; j++)
	         if(adj[i][k] + adj[k][j] < adj[i][j])
	           adj[i][j] = adj[i][k] + adj[k][j];
}

void clearBuffer(int v[MAX][MAX]){
register int i, j;

	for(i=0; i<LIM; i++){
	   for(j=0; j<LIM; j++)
	      v[i][j] = INF;
	   v[i][i] = 0;
	}
}

void show(int v[MAX][MAX], int n){
int i, j;

	for(i=0; i<n; i++){
	   for(j=0; j<n; j++)
	      cout << v[i][j] << " ";
	   cout << endl;
	}
}

main(){
int adjM[MAX][MAX], adjY[MAX][MAX], cost;
int n, i, ivt1, ivt2, min, pos;
char road, direct, vt1, vt2;

	cin >> n;
	while(n!=0){
	     clearBuffer(adjM);
	     clearBuffer(adjY);
	     for(i=0; i<n; i++){
	         cin >> road >> direct >> vt1 >> vt2 >> cost;
	         if(road=='Y'){
	           if(cost < adjY[(int)vt1-65][(int)vt2-65]){
	              adjY[(int)vt1-65][(int)vt2-65] = cost;
	              if(direct=='B')
	                 adjY[(int)vt2-65][(int)vt1-65] = cost; 
	           }
	         }
	         else{
	            if(cost < adjM[(int)vt1-65][(int)vt2-65]){
	              adjM[(int)vt1-65][(int)vt2-65] = cost;
	              if(direct=='B')
	                 adjM[(int)vt2-65][(int)vt1-65] = cost; 
	            }
	         }
	     }
	     cin >> vt1 >> vt2;
	     floyd(adjM);
	     floyd(adjY);
	     ivt1 = (int)vt1-65;
	     ivt2 = (int)vt2-65;
     	     min = INF;
	     for(i=0; i<26; i++)
	        if(adjY[ivt1][i] + adjM[ivt2][i] < min)
	           min = adjY[ivt1][i] + adjM[ivt2][i];
	    if(min<INF){       
	       cout << min;
	       for(i=0; i<26; i++)
	          if(adjY[ivt1][i] + adjM[ivt2][i] == min)
	             printf(" %c",i+65);
	       cout << endl;
	    }
	    else
	       cout << "You will never meet.\n";
	     cin >> n;
	}
}
	
