#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>

#define INF 10000000.0
#define MAXLINE 10000
#define MAXV 1000 
#define TRUE 1

double adj[MAXV][MAXV];

using namespace std;

int main(){
int tests;
int tmp[MAXV];
int index, len, aux, label;
int labA, labB;
int x0, y0, x1, y1;
int xA, yA, xB, yB;
char str[MAXLINE];
map< pair < int, int > , int> xyToindex;
map< int, pair < int, int > > indexToxy;
double weight;
bool first = true;

	scanf("%d\n",&tests);
	while(tests--){
	     if(!first)
	        printf("\n");
	     first = false;
	     
	     scanf("%d %d %d %d\n",&x0, &y0, &x1, &y1);
	     
	     if(x0 == x1 && y0 == y1){
	        printf("0\n");
	        continue;
	     }
	        
	     
	     index = 0;
	     label = 0;
	     xyToindex.clear();
	     indexToxy.clear();
	     
	     xyToindex[ make_pair(x0, y0) ] = label;
	     indexToxy[label++] = make_pair(x0, y0);
	     xyToindex[ make_pair(x1, y1) ] = label;
	     indexToxy[label++] = make_pair(x1, y1);
	     
	     for(int i=0; i<MAXV; i++){
	         for(int j=0; j<MAXV; j++)
	             adj[i][j] = INF;
	         adj[i][i] = 0;
	     }
	        

	     while(gets(str)){
	          len = strlen(str);
	          if(len == 0)
	             break;
	          
	          for(int i=0; i<len; i++){
	              if(i == 0 || str[i] == ' '){
	                 aux = atoi(&str[i]);
	                 if(aux >=0)
	                    tmp[index++] = aux;
	              }
	          }
	          
	          for(int i=0; i<index-2; i+=2){
                  if( xyToindex.count( make_pair(tmp[i], tmp[i+1])  ) <= 0){
	                 xyToindex[ make_pair(tmp[i], tmp[i+1]) ] = label;
	                 indexToxy[label] = make_pair(tmp[i], tmp[i+1]);
	                 label++;
	              }
	              if( xyToindex.count( make_pair(tmp[i+2], tmp[i+3])  ) <= 0){
	                 xyToindex[ make_pair(tmp[i+2], tmp[i+3]) ] = label;
	                 indexToxy[label] = make_pair(tmp[i+2], tmp[i+3]);	                 
	                 label++;
	              }
                  labA = xyToindex[ make_pair(tmp[i], tmp[i+1]) ];
                  labB = xyToindex[ make_pair(tmp[i+2], tmp[i+3]) ];

	              weight = 0.0015*sqrt( (tmp[i] - tmp[i+2])*(tmp[i] - tmp[i+2]) + 
	                                   (tmp[i+1] - tmp[i+3])*(tmp[i+1] - tmp[i+3]));
	              adj[labA][labB] = weight;
	              adj[labB][labA] = weight;
	              
	          }
	          index = 0;
	     }
	     
	     for(int i=0; i<label; i++)
	        for(int j=0; j<label; j++)
	            if(i != j && adj[i][j] == INF){
	               xA = indexToxy[i].first;
	               yA = indexToxy[i].second;
	               xB = indexToxy[j].first;
	               yB = indexToxy[j].second;
	               weight = 0.006*sqrt((xA - xB)*(xA - xB) + (yA - yB)*(yA - yB));
	               adj[i][j] = weight;
	            }
	     for(int k=0; k<label; k++)
	         for(int i=0; i<label; i++)
	             for(int j=0; j<label; j++)
	                 if(adj[i][k] + adj[k][j] < adj[i][j])
	                    adj[i][j] = adj[i][k] + adj[k][j];
	     printf("%d\n", (int)round(adj[0][1]));
	     	                
	
	}

}

