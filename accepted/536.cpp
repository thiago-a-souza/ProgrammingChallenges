#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<queue>

#define MAX 30 

using namespace std;

typedef struct {
char info;
int right, left;
} TNode;

TNode nodes[MAX*2];
char pre[MAX], in[MAX];
int pos, p2;
int len;

int construct_tree(int inStart, int inFinal){
int inIndex;
int aux;

	if(inStart < 0 || inStart > inFinal || inFinal > len || inStart > len)
	   return -1;
    aux = pos;
	nodes[pos++].info = pre[p2++];
	for(int i=inStart; i<=inFinal; i++){
	   if(in[i] == nodes[aux].info){
	      inIndex = i;
	      break;
	   }
	}
	nodes[aux].left = construct_tree(inStart,inIndex-1);
	nodes[aux].right= construct_tree(inIndex+1, inFinal);
	
	return aux;
	
}

void postOrder(int index){
     if(index < 0 || index >= pos)
        return;
     postOrder(nodes[index].left);
     postOrder(nodes[index].right);
     printf("%c",nodes[index].info);
}

main(){

	while(scanf("%s %s",pre,in) != EOF){
	     len = strlen(pre);
	     pos = 0;
	     p2 = 0;
	     construct_tree(0, len-1);
	 /*    for(int i=0; i<pos; i++)
	        if(nodes[i].info >= 0){
	           printf("%c left= ", nodes[i].info);
	           if(nodes[i].left >= 0)
	              printf("%c",nodes[nodes[i].left].info);
	           printf(" right= ");
	           if(nodes[i].right >= 0)
	              printf("%c",nodes[nodes[i].right].info);
	           printf("\n");
	        } */
	    for(int i=0; i<pos; i++)
	       if(nodes[i].info == pre[0]){
	          postOrder(i);
	          printf("\n");
	          break;
	       }
	}

}

