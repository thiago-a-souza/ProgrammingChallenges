#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define LEFT(i) ((2*i) + 1)
#define RIGHT(i) ((2*i) + 2)
#define PARENT(i) ((i-1)/2)

#define MAX 500
#define MAXLINE 1000

#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

void parse(char *line, int *order){
int i = 0, index = 0, len;

	len = strlen(line);
	while(i < len){
	      while(i < len && !(line[i] >= '0' && line[i] <= '9'))
	            i++;
	      order[index++] = atoi(&line[i]) - 1;
	      while(i < len && line[i] >= '0' && line[i] <= '9')
	            i++;
	}
}

int main(){
char line[MAXLINE];
int n, m, len;
int order[MAX];
int tree[MAX];
int minLeaf;
int cs = 1;

	while(true){
	     scanf("%d\n",&n);
	     if(n == 0)
	        break;
	     minLeaf = 1;
	     for(int i=0; i<n; i++)
	         minLeaf = minLeaf*2;
         minLeaf--;
	    
	     cin.getline(line, MAXLINE);
	     parse(line, order);
	     
	     cin.getline(line, MAXLINE);
	     len = strlen(line);
	     for(int i=0, j=minLeaf; i<len; i++, j++)
	         tree[j] = (int)(line[i] - '0');
	     
	     int maxNode = 1, index = 0;    
         for(int h =0; h<n; h++){
             for(int i=0; i<maxNode; i++){
                tree[index++] = order[h];
             }
             maxNode *= 2;
         }          

	     scanf("%d\n", &m);
	     
	     printf("S-Tree #%d:\n", cs++);
	     for(int i=0; i<m; i++){
	         cin.getline(line, MAXLINE);
	         index = 0; 
	         while(index < minLeaf){
	              if(line[tree[index]] == '0')
	                 index = LEFT(index);
	              else 
	                 index = RIGHT(index);
	         }
	         printf("%d", tree[index]);
	     }
	     printf("\n\n"); 
	     
	}
	return 0;
}

