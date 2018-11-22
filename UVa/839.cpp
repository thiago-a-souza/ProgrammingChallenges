#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 10000
#define MAXLINE 300

using namespace std;

typedef struct STree {
int left, right;
int weight;
int distLeft, distRight;
} Tree;

Tree tree[MAX];
int total;
bool valid;

int solution(int idx){

	if(!valid || idx < 0)
	   return 0;
		   
	if(tree[idx].weight == 0)
	  tree[idx].weight = solution(tree[idx].left) + solution(tree[idx].right);   
	
	if(tree[idx].left >= 0 && tree[idx].right >= 0 && 
	   tree[idx].distLeft*tree[tree[idx].left].weight != tree[idx].distRight*tree[tree[idx].right].weight)
	   valid = false;
	return tree[idx].weight;
	   
	  
}

void readInput(int myWeight, int idx){
char line[MAXLINE];
int Wl, Dl, Wr, Dr;

    
	if(myWeight > 0){
	   tree[idx].weight = myWeight;
	   tree[idx].left = tree[idx].right = -1;
	   tree[idx].distLeft = tree[idx].distRight = 0;
	   return;
	}   
	cin.getline(line, MAXLINE);
	if(strlen(line) == 0) {
	   return;
	}
	
	sscanf(line, "%d %d %d %d", &Wl, &Dl, &Wr, &Dr);
	
	tree[idx].weight    = myWeight;
	tree[idx].distLeft  = Dl;
	tree[idx].distRight = Dr;
	
	tree[idx].left      = ++total;
	readInput(Wl, total);
	
	tree[idx].right     = ++total;
	readInput(Wr, total);
}

int main(){
int tests;
char line[MAXLINE];
	scanf("%d\n\n", &tests);
	while(tests--){
	      total = 0; 
	      valid = true;

	      readInput(0, 0);
	      cin.getline(line, MAXLINE);
	      
	      solution(0);
	      
	      if(valid)
	         printf("YES\n");
	      else
	         printf("NO\n");
	    
	     if(tests > 0)
	         printf("\n");	      
	}
	return 0;
}

