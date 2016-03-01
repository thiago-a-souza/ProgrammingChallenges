#include<iostream>
#include<cstdio>
#include<queue>
#define MAX_V 100
#define MAX_A 10

using namespace std;

typedef struct {
int x, y;
} TAdj;

TAdj adj[MAX_V][MAX_A];
int grau[MAX_V];
int d[MAX_V];

void bfs(int inicio){
int s, t;
queue<int> Q;
int visited[MAX_V];

        memset(visited, 0, sizeof(visited));
        d[inicio] = 0;
        visited[inicio] = 1;
        Q.push(inicio);
        while(!Q.empty()){
              s = Q.front();
              Q.pop();
              for(int i=0; i<grau[s]; i++) {
                  t = adj[s][i].x*10 + adj[s][i].y;
                  if(!visited[t]){
                     visited[t] = 1;
                     d[t] = d[s] + 1;
                     Q.push(t);
                  }
              }
        }
}

main(){
char ch[4];
TAdj src, dst;
        for(int i=0; i<MAX_V; i++)
            grau[i] = 0;

        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++){
                if(i-1 >=0){
                   if(j-2 >= 0){
                      adj[i*10+j][grau[i*10+j]].x = i-1;
                      adj[i*10+j][grau[i*10+j]].y = j-2;
                      grau[i*10+j]++;
                   }
                   if(j+2 < 8){
                      adj[i*10+j][grau[i*10+j]].x = i-1;
                      adj[i*10+j][grau[i*10+j]].y = j+2;
                      grau[i*10+j]++;
                   }
                   if(i-2 >= 0){
                     if(j-1 >= 0){
                       adj[i*10+j][grau[i*10+j]].x = i-2;
                       adj[i*10+j][grau[i*10+j]].y = j-1;
                       grau[i*10+j]++;
                     }
                     if(j+1 < 8){
                        adj[i*10+j][grau[i*10+j]].x = i-2;
                        adj[i*10+j][grau[i*10+j]].y = j+1;
                        grau[i*10+j]++;
                     }
                   }
                }
                
                if(i+1 < 8){
                   if(j-2 >=0){
                      adj[i*10+j][grau[i*10+j]].x = i+1;
                      adj[i*10+j][grau[i*10+j]].y = j-2;
                      grau[i*10+j]++;
                   }
                   if(j+2 < 8){
                      adj[i*10+j][grau[i*10+j]].x = i+1;
                      adj[i*10+j][grau[i*10+j]].y = j+2;
                      grau[i*10+j]++;
                   }
                   
                  if(i+2 < 8){
                     if(j-1 >= 0){
                        adj[i*10+j][grau[i*10+j]].x = i+2;
                        adj[i*10+j][grau[i*10+j]].y = j-1;
                        grau[i*10+j]++;
                     }
                     if(j+1 < 8){
                        adj[i*10+j][grau[i*10+j]].x = i+2;
                        adj[i*10+j][grau[i*10+j]].y = j+1;
                        grau[i*10+j]++;
                     }
                  }
                }
            }
                
            
        while(scanf("%s",ch) != EOF){
             src.x = (int)ch[0] - 97;
             src.y = (int)ch[1] - 49;
             scanf("%s",ch);
             dst.x = (int)ch[0] - 97;
             dst.y = (int)ch[1] - 49;
             //printf("%d %d....%d %d\n",src.x,src.y,dst.x,dst.y);
             for(int i=0; i<MAX_V; i++)
                 d[i] = 0;
             bfs(src.x*10+src.y);
             printf("To get from %c%d to %c%d takes %d knight moves.\n",(char)src.x+97,src.y+1,(char)dst.x+97,dst.y+1,d[dst.x*10+dst.y]);
             
        }

        

}


