#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define INF 2000000
#define MAX 200000
#define MAXLINE 100000

using namespace std;

typedef struct {
int left, right;
int val;
} Tree;

Tree tree[MAX];
int pos;
int minPath, minVal;

int buildTree(int *in, int *post, int len){
int aux;

	if(len == 0)
	   return -1;
	   
	aux = pos;
	pos++;
	   
	int i = len - 1;
	while(post[len-1] != in[i])
	      i--;


	tree[aux].val = post[len-1];
	tree[aux].left = buildTree(in, post, i);
	tree[aux].right = buildTree(in + i + 1, post + i, len-i-1);


	return aux;
}

void findMinPath(int index, int sum){

	if(index < 0)
	   return;

	if(tree[index].left < 0 && tree[index].right < 0){
	   if(sum + tree[index].val < minPath || (sum + tree[index].val == minPath && tree[index].val < minVal) ){
	      minPath = sum + tree[index].val;
	      minVal = tree[index].val;
// 	      printf("minPath = %d, minVal = %d\n", minPath, minVal);
	   } 
	   return;
	}

	findMinPath(tree[index].left, sum + tree[index].val);
	findMinPath(tree[index].right, sum + tree[index].val);	
// 	printf("%d", tree[index].val);

}

void preOrder(int index){

	if(index < 0)
	   return;
	   
	printf("%d => %d %d\n", tree[index].val, tree[index].left >= 0 ? tree[tree[index].left].val : -1, tree[index].right >= 0 ? tree[tree[index].right].val : -1);
	preOrder(tree[index].left);
	preOrder(tree[index].right);	

}

void parse(char *line, int *v, int *n){
int i = 0, len;

    *n = 0;

	len = strlen(line);
	while(i < len){
	      while(i < len && line[i] == ' ') 
	            i++;
	      v[*n] = atoi(&line[i]);
	      *n = *n + 1;
	      while(i < len && line[i] >= '0' && line[i] <= '9') 
	            i++;
	}
}

int main(){
int in[MAX], post[MAX], n;
char line[MAXLINE];

    while(cin.getline(line, MAXLINE)){
          parse(line, in, &n);
          cin.getline(line, MAXLINE);
          parse(line, post, &n);

          pos = 0;
          buildTree(in, post, n);
                    
          minPath = INF;
          findMinPath(0, 0);
          cout << minVal << endl;
//           preOrder(0);
    }
	return 0;
}

