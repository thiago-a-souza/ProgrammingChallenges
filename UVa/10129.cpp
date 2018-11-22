#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAXLINE 1000
#define MAX 30
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int adj[MAX][MAX], in[MAX], out[MAX], p[MAX];
bool used[MAX];

int findSet(int x){
      if(x != p[x])
        p[x] = findSet(p[x]);
      return p[x];
}

bool test1(){
	for(int i=0; i<MAX; i++)
        if(used[i] && in[i] != out[i])
	       return false;
	return true;	
}

bool test2(){
int v[2], index = 0;

	for(int i=0; i<MAX; i++)
        if(used[i] && in[i] != out[i]){
           if(index > 1)
              return false;
           v[index++] = i;
	    }

	if( (in[v[0]] == out[v[0]] + 1 && in[v[1]] + 1 == out[v[1]] ) || 
	    (in[v[0]] + 1 == out[v[0]] && in[v[1]] == out[v[1]] + 1 ) )
         return true;
	return false;
	
}

void solve(){
bool flag, flag2;
int v[2], index;
int u_set, v_set;

	if(!test1() && !test2()){
	   printf("The door cannot be opened.\n");
	   return;
	}

	for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++){
	       if(adj[i][j] > 0){
	          u_set = findSet(i);
	          v_set = findSet(j);
	          if(u_set != v_set)
	             p[v_set] = p[u_set];
	       }
	     }
    
	flag = true;
	for(int i=0; i<MAX; i++){
	    if(used[i]){
	       u_set = findSet(i);
	       for(int j=i+1; j<MAX; j++)
	          if(used[j]){
	             v_set = findSet(j);	             
	             if(u_set != v_set){
	                printf("The door cannot be opened.\n");
	                return;
	             }
	          }
	    }
	}
    printf("Ordering is possible.\n");
}

int main(){
int u, v;
int tests, n, len;
char word[MAXLINE];
bool flag;

	scanf("%d",&tests);
	while(tests--){
	     scanf("%d", &n);
	     memset(adj, 0, sizeof(adj));
	     memset(in, 0, sizeof(in));
	     memset(out, 0, sizeof(out));
	     memset(used, 0, sizeof(used));
	     for(int i=0; i<MAX; i++)
	         p[i] = i;
	         
	     for(int i=0; i<n; i++){
	        scanf("%s", word);
	        len = strlen(word);
	        u = word[0] - 'a';
	        v = word[len-1] - 'a';
	        used[u] = used[v] = true;
	        adj[u][v] = 1;
	        out[u]++; in[v]++; 
	     }	     
	     solve();
  
	}
	return 0;
}

