#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000000

using namespace std;

int M[MAX], A[MAX];
int pos[MAX], dc[MAX];

void build_segment_tree(int node, int start, int end){

	if(start == end){
	   M[node] = start;
	} else {
	  int left = 2*node;
	  int right = 2*node + 1;
	  int mid = (start+end)/2;
	  
	  build_segment_tree(left, start, mid);
	  build_segment_tree(right, mid+1, end);
	  
	  if(A[M[2*node]] >= A[M[(2*node)+1]])
	     M[node] = M[2*node];
	  else
	     M[node] = M[(2*node)+1];
	}

}

int query_segment_tree(int node, int start, int end, int i, int j){
int p1, p2;

	if(i > end || j < start)
	   return -1;
	if(start >= i && end <= j)
	   return M[node];

	int left = node*2;
	int right = node*2 + 1;
	int mid = (start + end)/2;
	p1 = query_segment_tree(left,  start, mid, i, j);
	p2 = query_segment_tree(right, mid+1, end, i, j);

	if( p1 == -1)
	   return p2;
	if( p2 == -1)
	   return p1;
	   
	if( A[p1] >= A[p2] )
	   return p1;
	return p2;
}

main(){
int n, q;
int last, current;
int index;
int x, y;

	while(true){
		scanf("%d",&n);
		if(n == 0)
		   break;
		scanf("%d",&q);
		memset(A, 0, sizeof(A));
		memset(M, 0, sizeof(M));
		
		index = 0;
		A[0] = 1;
		pos[0] = 0;
		dc[0] = 0;
		scanf("%d",&last);
		for(int i=1; i<n; i++){
			scanf("%d",&current);
			if(last == current){
				A[index]++;
				pos[i] = index;
				dc[i] = dc[i-1] + 1;
			} else {
			    A[++index]++;
			    pos[i] = index;
			    dc[i] = 0;
			}
			last = current;
		}
		build_segment_tree(1, 0, index);
		for(int i=0; i<q; i++){
		   scanf("%d %d",&x,&y);
		   x--; y--;
		   if(pos[x] == pos[y]){
		      printf("%d\n",dc[y]-dc[x]+1);
		   } else if(x == y){
		      printf("1\n");
		   } else if(pos[x] + 1 == pos[y]){
		             if(A[pos[x]] - dc[x] >= dc[y] + 1)
		               printf("%d\n",A[pos[x]] - dc[x]);
		             else
		               printf("%d\n",dc[y] + 1);
		   } else if(pos[x] + 2 == pos[y]){
		             int len1 = A[pos[x]] - dc[x];
		             int len2 = dc[y] + 1;
		             int len3 = A[pos[x]+1];
		          
		             if(len1 >= len2 && len1 >= len3)
		                printf("%d\n",len1);
		             else if(len2 >= len1 && len2 >= len3)
		                     printf("%d\n",len2);
		             else printf("%d\n",len3);
		   } else {
		      int len1 = A[pos[x]] - dc[x];
		      int len2 = dc[y] + 1;
   		      int idx = query_segment_tree(1,0,index, pos[x]+1,pos[y]-1);
   		      int len3 = A[idx];
		      if(len1 >= len2 && len1 >= len3)
		         printf("%d\n",len1);
		      else if(len2 >= len1 && len2 >= len3)
		              printf("%d\n",len2);
		      else printf("%d\n",len3);
		   }
		}
		
			
		
	}
}

