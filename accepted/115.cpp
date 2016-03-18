#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>


#define MAX 1000
#define MAXNAME 100

using namespace std;

int tree[MAX][MAX], p[MAX], grau[MAX], visited[MAX];
int ans;

void isChild(int index, int key, int level){

	if(index < 0)
	   return;
	if(visited[index] == 1)
	   return;
	visited[index] = 1;
	for(int i=0; i<grau[index]; i++)
	   if(tree[index][i] == key){
	      ans = level;
	      return;
	   }
   
    for(int i=0; i<grau[index]; i++)
       isChild(tree[index][i], key, level + 1);
       
    return;
}

void findSolution(int u, int v){
int m = 0, n;
int index;

	if(u < 0 || v < 0){
	   printf("no relation\n");
	   return;
	}
	   

	if(p[u] == p[v]){
	   printf("sibling\n");
	   return;
    }
    
    ans = -1;
    isChild(u, v, 0);
    if(ans >= 0){
       if(ans == 0)
          printf("parent\n");
       else if(ans == 1)
               printf("grand parent\n"); 
       else {
            for(int i=2; i<=ans; i++)
                printf("great ");
            printf("grand parent\n");
       }
      return;
    }
    
    ans = -1;
    isChild(v, u, 0);
    if(ans >= 0){
       if(ans == 0)
          printf("child\n");
       else if(ans == 1)
               printf("grand child\n"); 
       else {
            for(int i=2; i<=ans; i++)
                printf("great ");
            printf("grand child\n");
       }
      return;
    }    
	
	index = p[u];
	m = 0;
	while(index >= 0){
	      ans = -1;
	      isChild(index, v, 0);
	      if(ans >= 0){
	         if(abs(m-ans) == 0)
	            printf("%d cousin\n", min(m, ans));
	         else   
   	            printf("%d cousin removed %d\n", min(m, ans), abs(m-ans));
	         return;
	      }
	      index = p[index];
	      m++;
	      
	}
	
	
	printf("no relation\n");

}

int main(){
map<string, int> dic;
char child[MAXNAME], parent[MAXNAME];
int nodes = 0;
int indexChild, indexParent;

	memset(grau, 0, sizeof(grau));
	memset(p, -1, sizeof(p));
	dic.clear();
	while(true){
         scanf("%s %s", child, parent);
         if(strcmp(child, "no.child") == 0)
            break; 
            
         if(dic.count(child) == 0)
            dic[child] = nodes++;
         if(dic.count(parent) == 0)
            dic[parent] = nodes++;	       
              
         indexChild = dic[child];
         indexParent = dic[parent];
         
         tree[indexParent][grau[indexParent]++] = indexChild;
         p[indexChild] = indexParent;
	}
	
	while(scanf("%s %s", child, parent) != EOF){
          indexChild = -1; indexParent = -1; 

          if(dic.count(child) > 0)
             indexChild = dic[child];
          
          if(dic.count(parent) > 0)
             indexParent = dic[parent];

          memset(visited, 0, sizeof(visited));
	      findSolution(indexChild, indexParent);
	}
	return 0;
}


