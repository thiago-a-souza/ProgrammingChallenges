/* Minimal coverage 
   Category: Greedy
*/
#include<iostream>
#include<cstdio>

using namespace std;

#define ff(i,v,n) for(int i=v; i<n; i++)
#define f(i,n) ff(i,0,n)
#define MAXSIZE 100001
#define debug(x) 

typedef struct{
int left, right;
} TSegm;

TSegm segm[MAXSIZE];
TSegm ans[MAXSIZE];
int M, nro_segm, nro_ans;


int cmp(const void *a, const void *b){
TSegm *p1, *p2;

	p1 = (TSegm*)a;
	p2 = (TSegm*)b;
	
	if(p1->left < p2->left)
	  return -1;
	if(p1->left > p2->left)
	  return 1;
	if(p1->right < p2->right)
	  return -1;
	if(p1->right > p2->right)
	  return 1;
	return 0;

}

int main(){
int tests, a, b, count;

	scanf("%d",&tests);
	while(tests--){
	     scanf("%d",&M);
	     
	     nro_segm = 0;
	     nro_ans = 0;
	     count = 0;
	     
	     
	     while(true){
	          scanf("%d %d",&a,&b);
	          if(a == 0 && b == 0)
	             break;
	          segm[nro_segm].left = a;
	          segm[nro_segm].right = b;
	          nro_segm++;
	     }
	     qsort(segm, nro_segm, sizeof(TSegm), cmp);

	     
	     int pos = 0;
	     int left = 0, right = 0, curr_left;
	     count = 0;
	     
	     while(pos < nro_segm && right < M){
	           if(segm[pos].left <= left && segm[pos].right >= right && right < M){
		       curr_left = segm[pos].left;
		       right = segm[pos].right;
		       pos++; count++;
		       while(pos < nro_segm && segm[pos].left <= left){
		             if(segm[pos].right >= right){
		                right = segm[pos].right;
		                curr_left = segm[pos].left;
		             }
		             pos++;
		       }
		       left = right;
		       ans[nro_ans].left = curr_left;
		       ans[nro_ans].right = right;
		       nro_ans++;
	           } else 
	                  pos++;
	     }
	     
	     if(right >= M){
	        printf("%d\n",count);
	        f(i, nro_ans)
	            printf("%d %d\n",ans[i].left,ans[i].right);
	     }
	     else
	        printf("0\n");
	     if(tests != 0)
	        printf("\n");
	}
}



