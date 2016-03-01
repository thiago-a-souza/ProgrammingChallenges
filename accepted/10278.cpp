#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>

#define MAX 501
#define INF 100000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int F[MAX]; 
bool isF[MAX];
int firestations, intersections;

typedef struct{
int v, w;

} TAdj;

TAdj adj[MAX][MAX];
int grau[MAX];

int dijkstra(int inicial){
priority_queue< pair <int, int> >  heap;
int s, t, peso;
int d[MAX];

	for(int i=1; i<=intersections; i++)
	   d[i] = INF;
	for(int i=0; i<firestations; i++)
	   heap.push(make_pair(d[F[i]] = 0, F[i])); 
	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
	      s = heap.top().second;
	      heap.pop();
	      for(int i=0; i<grau[s]; i++){
	         t = adj[s][i].v;
	         peso = adj[s][i].w;
	         if(d[s] + peso < d[t]){
	            d[t] = d[s] + peso;
	            heap.push(make_pair(-d[t], t));
	         }
	      }
	}
	peso = -INF;

	for(int i=1; i<=intersections; i++)
	   if(d[i] > peso)
	      peso = d[i];
	return peso;

}

void parse(char *str, int len, int *a, int *b, int *c){
int index = 0;

	*a = atoi(&str[0]); 
	while(str[index] != ' ' && index < len)
	     index++;
	*b = atoi(&str[index]);
	while(str[index] == ' ' && index < len)
	     index++;
	while(str[index] >= '0' && str[index] <= '9' && index < len)
	      index++;
	while(str[index] != ' ' && index < len)
	     index++;
    *c = atoi(&str[index]);	

}

int main(){
int tests, s, t, w;
int auxDist, ansDist, ansIndex;
char str[100];
int len;

    scanf("%d",&tests);
	while(tests--){
	     scanf("%d %d\n",&firestations, &intersections);
	     memset(grau, 0, sizeof(grau));	     
	     memset(isF, 0, sizeof(isF));

	     for(int i=0; i<firestations; i++){
	         scanf("%d\n",&F[i]);
	         isF[F[i]] = true;
	     }
	     if(intersections == 1){
	        printf("1\n");
	        if(tests > 0)
	           printf("\n");
	        continue;
	     }
   

		while(cin.getline(str, MAX)){
		      len = strlen(str);
		      if(len == 0)
		         break;
		      parse(str, len, &s, &t, &w);
              adj[s][grau[s]].v = t;
	          adj[s][grau[s]].w = w;
	          grau[s]++;
	        
	          adj[t][grau[t]].v = s;
	          adj[t][grau[t]].w = w;
	          grau[t]++;
		     
		}
	     
	     ansDist = INF;	ansIndex = 1;
	     for(int i=1; i<=intersections; i++){
	        if(isF[i])
	           continue;
	        auxDist = dijkstra(i);
	        if(auxDist < ansDist){
	           ansDist = auxDist;
	           ansIndex = i;
	        }
	     }
	     
	   
	     printf("%d\n", ansIndex);
	     if(tests > 0)
	        printf("\n");
	          	     
	}
	return 0;
}

