#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 20

using namespace std;

typedef struct {
int left, right;
} TDomino;

int N, M;
TDomino start, end, dominoes[MAX];
bool used[MAX];
bool ans;

void construct_candidates(int key, TDomino c[], int *ncand, int indexes[]){
bool b;

	*ncand = 0;
	for(int i=0; i<M; i++)
	   if(!used[i] && (dominoes[i].left == key || dominoes[i].right == key)){
	         c[*ncand] = dominoes[i];
	         indexes[*ncand] = i;
	         *ncand = *ncand + 1;
	   }
}

void backtrack(TDomino a[], int k, int n){
TDomino c[MAX];
int ncand;
int indexes[MAX];

	if(k > n || ans)
	   return;
	
	
	   
	if(k == n && a[k].right == end.left){
	   ans = true;
	} else {      	   
		construct_candidates(a[k].right, c, &ncand, indexes);
		k++;
		for(int i=0; i<ncand; i++){
		    if(a[k-1].right == c[i].left){
		       a[k].left = c[i].left;
		       a[k].right = c[i].right;
		    } else {
		       a[k].left = c[i].right;
		       a[k].right = c[i].left;
		    }
		    used[indexes[i]] = true;
			backtrack(a,k,n);
			used[indexes[i]] = false;
		}	
	}
}

main(){
TDomino a[MAX];
bool used[MAX];

	while(true){
		scanf("%d",&N);
		if(N == 0)
		   break;
		scanf("%d",&M);
		scanf("%d %d",&start.left, &start.right);
		scanf("%d %d",&end.left, &end.right);
		for(int i=0; i<M; i++)
		   scanf("%d %d",&dominoes[i].left,&dominoes[i].right);
		a[0].left = start.left;
		a[0].right = start.right;
		
		
		ans = false;
		backtrack(a, 0, N);
		if(ans)
		   printf("YES\n");
		else
		   printf("NO\n");
	}
}

