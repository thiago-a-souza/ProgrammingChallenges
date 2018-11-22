#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

#define MAXL 100
#define MAXS 3000
#define INF 99999999

typedef struct {
char ch;
int len;
int lng1, lng2;
} TDic;

TDic dic[MAXS];

typedef struct {
int v, w;
} TAdj;

TAdj adj[MAXS][MAXS];
int grau[MAXS], d[MAXS];

using namespace std;

void dijkstra(int inicial){
priority_queue< pair<int, int> > heap;
int s, t, peso;

	for(int i=0; i<MAXS; i++)
	    d[i] = INF; 

	heap.push(make_pair(d[inicial] = dic[inicial].len, inicial));
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
}

void constructGraph(int n){
	
	memset(grau, 0, sizeof(grau));
	
	for(int i=0; i<(n-1); i++)
	   for(int j=i+1; j<n; j++)
	      if( dic[i].ch != dic[j].ch ) {
	          if(dic[i].lng1 == dic[j].lng1 || dic[i].lng1 == dic[j].lng2 ||
	             dic[i].lng2 == dic[j].lng1 || dic[i].lng2 == dic[j].lng2){
	             
	             adj[i][grau[i]].v = j;
	             adj[i][grau[i]].w = dic[j].len;
	             grau[i]++;
	             
	             adj[j][grau[j]].v = i;
	             adj[j][grau[j]].w = dic[i].len;
	             grau[j]++;
              }
		  }
}

main(){
char src[MAXL], dst[MAXL];
char a[MAXL], b[MAXL], c[MAXL];
int n, u, v, len, label;
int ans;
map<string, int> mp;

		while(true){
		     scanf("%d",&n);
		     if(n == 0)
		        break;
		        
		     label = 1;

		     memset(src, '\0', sizeof(src));
		     memset(dst, '\0', sizeof(dst));
		     mp.clear();
		     
		     scanf("%s %s",src, dst);
		     mp[src] = label++;
		     mp[dst] = label++;
		     
		     for(int i=0; i<n; i++){
		        memset(a, '\0', sizeof(a));
		        memset(b, '\0', sizeof(b));
		        memset(c, '\0', sizeof(c));
		        
		        scanf("%s %s %s",a,b,c);
		        
		        if(mp[a] <= 0)
		           mp[a] = label++;
		        if(mp[b] <= 0)
		           mp[b] = label++;

		        u = mp[a]; v = mp[b];

		        len = strlen(c);
		        dic[i].ch = c[0];
		        dic[i].lng1 = u;
		        dic[i].lng2 = v;
                dic[i].len = len;
		     }

  
            constructGraph(n);
            u = mp[src]; v = mp[dst];
            if( u == v ){
               printf("0\n");
               continue;
            }
            ans = INF;
            for(int i=0; i<n; i++){
                if(dic[i].lng1 == u && dic[i].lng2 == v && dic[i].len < ans){
                   ans = dic[i].len;
                } else if(dic[i].lng1 == u || dic[i].lng2 == u){
                          dijkstra(i);
                          for(int j=0; j<n; j++)
                              if((dic[j].lng1 == v || dic[j].lng2 == v) && d[j] < ans){
                                 ans = d[j];
                              }
                }
                
            }
            if(ans >= INF)
               printf("impossivel\n");
            else
               printf("%d\n",ans);
		            
		                
		}
	
	
}

