#include<iostream>
#include<cstdio>
#include<queue>
#include<map>

#define MAX_V 10000
#define MAX_A 10000

using namespace std;

int adj[MAX_V][MAX_A];
int grau[MAX_V];
int p[MAX_V];
int path_inv[MAX_V], p_count;
map< string, int > m;
map< int, string > m_inv;

void path(int i){
   
      if(p[i] == -1)
         path_inv[p_count++] = i;
      else {
         path(p[i]);
         path_inv[p_count++] = i;
         //cout << m_inv[i] << endl;
      }
}

void bfs(int inicio){
int s, t;
int visited[MAX_V];
queue<int> Q;
        memset(visited, 0, sizeof(visited));
        memset(p, -1, sizeof(p));
 
        visited[inicio] = 1;
        Q.push(inicio);
        
        while(!Q.empty()){
          s = Q.front();
          Q.pop();
          for(int i=0; i<grau[s]; i++) {
             t = adj[s][i];
             if(!visited[t]){
                visited[t] = 1;
                p[t] = s;
                Q.push(t);
             }
          }
        }
}

main(){
int n, count, ct1, ct2, line=0;
char city1[10], city2[10];

        while(scanf("%d",&n) != EOF){
             if(line > 0)
                printf("\n");
             line++;
             count = 1;
             p_count = 0;
             m.clear();
             m_inv.clear();
             for(int i=0; i<MAX_V; i++)
                 grau[i] = 0;
             
             for(int i=0; i<n; i++){
                 scanf("%s %s",city1,city2);
                 if(m.find(city1) == m.end()){
                    m[city1] = count;
                    m_inv[count] = city1;
                    count++;
                 }
                 if(m.find(city2) == m.end()){
                    m[city2] = count;
                    m_inv[count] = city2;
                    count++;
                 }
                 ct1 = m[city1];
                 ct2 = m[city2];
                 adj[ct1][grau[ct1]] = ct2;
                 adj[ct2][grau[ct2]] = ct1;
                 grau[ct1]++;
                 grau[ct2]++;
             }
             scanf("%s %s",city1,city2);
             ct1 = m[city1];
             ct2 = m[city2];
             
             bfs(ct1);
             path(ct2);
             if(p_count > 1){
                for(int i=0; i<p_count-1; i++)
                    cout << m_inv[path_inv[i]] << " " << m_inv[path_inv[i+1]] << endl;
             }
             else
                 printf("No route\n");

        }

}

