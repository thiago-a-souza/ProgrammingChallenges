#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cmath>

typedef struct {
char info;
int left, right;
} Node;

Node tree[100];
char in[100], pre[100];
int pos, pIndex, n;

using namespace std;

int constructTree(int start, int end){
int aux, index;
    if(start < 0 || start >= n || end < 0 || end >= n || start > end)
       return -1;
    aux = pos;
    
    tree[pos++].info = pre[pIndex++];
    for(int i=start; i<=end; i++)
       if(in[i] == tree[aux].info){
          index = i;
          break;
       }
    tree[aux].left = constructTree(start,index-1);
    tree[aux].right = constructTree(index+1, end);
    return aux;
}

void postOrder(int n){
     if(n < 0)
        return;     
     postOrder(tree[n].left);
     postOrder(tree[n].right);
     printf("%c",tree[n].info);
}




main(){
int c;
	scanf("%d",&c);
	while(c--){
	     scanf("%d %s %s",&n,pre,in);
	     pos = 0; 
	     pIndex = 0;
	     constructTree(0, n-1);
	     for(int i=0; i<pos; i++)
	        if(tree[i].info == pre[0]){
               postOrder(i);
               break;
            }
	     printf("\n");
	}
}

