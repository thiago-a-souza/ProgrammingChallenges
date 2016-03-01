#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>
#include<queue>


#define MAX 30 
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define INF 10000

int adj[MAX][MAX], grau[MAX], dist[MAX];
double val[MAX];
bool willingness[MAX];
int N;
double cost[MAX];

using namespace std;


void bfs(int inicio){
int s, t;
queue<int> Q;
int visited[MAX];

	memset(visited, 0, sizeof(visited));
	dist[inicio] = 0;
	while(!Q.empty()){
	      s = Q.front();
	      Q.pop();
	      for(int i=0; i<grau[s]; i++){
	         t = adj[s][i];
	         if(visited[t] == 0){
	            visited[t] = 1;
	            dist[t] = dist[s] + 1;
	            Q.push(t);
	         }
	      }
	}
}


int main(){
char ch, str[100];
double d;
int u, v, len;

map<char, int> dic;
map<int, char> invDic;
int index;
int minhop;
double aux;
char ans[MAX];
int lenAns;

	while(scanf("%d\n",&N) != EOF){
	      memset(grau, 0, sizeof(grau));
	      memset(willingness, 0, sizeof(willingness));
	      memset(val, 0, sizeof(val));
	      memset(ans, '\0', sizeof(ans));
	      
	      dic.clear();
	      invDic.clear();
	      index = 0;
	      for(int i=0; i<N; i++){
	          scanf("%c %lf %s\n", &ch, &d, str);
	          
	          len = strlen(str);
	          if(dic.count(ch) == 0){
	             dic[ch] = index;
	             invDic[index] = ch;
	             index++;
	          }

	          u = dic[ch];
	          
	          val[u] = d;
	          for(int j=0; j<len; j++){
	             if(str[j] == '*')
	                willingness[u] = true;
	             else if((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z')){
                         if(dic.count(str[j]) == 0){
	                        dic[str[j]] = index;
	                        invDic[index] = str[j];
	                        index++;
	                     }
	                     
	                     v = dic[str[j]];	                     
	                     adj[u][grau[u]] = v;
	                     grau[u]++;
	             }       
	          }
	      }
	      
	      for(int i=0; i<index; i++){
	         cost[i] = val[i];
	         if(willingness[i] == false){
	            bfs(i);
	            minhop = INF;
	            for(int j=0; j<index; j++){
	               if(willingness[j] == true && dist[j] < minhop)
	                  minhop = dist[j];
	            }
	            for(int j=0; j<minhop; j++)
	               cost[i] = cost[i]*0.95;
	         }	         
	      }
	      
	      aux = 0.0; ch = 'z';
	      for(int i=0; i<index; i++){
	          if(cost[i] == aux && invDic[i] < ch)
	             ch = invDic[i];
	          else if(cost[i] > aux){
	                  aux = cost[i];
	                  ch = invDic[i];
	          }
	      }
	      
	      printf("Import from %c\n", ch);
	}
	return 0;
}

