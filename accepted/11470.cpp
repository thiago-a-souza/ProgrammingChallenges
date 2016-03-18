#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 100
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int mat[MAX][MAX];
int ans[MAX], sz;

void recur(int level, int len){
int ret = 0;

    if(len <= 0)
       return ;
    if(len == 1){
//        printf("%d\n", mat[level][level]);
       ans[sz++] = mat[level][level];
       return;
    }
    
       
	for(int s=0, j=level; s<len; s++, j++){
	    ret += mat[level][j] + mat[level+len-1][j];
// 	    printf(" (%d, %d) (%d, %d)", level, j, level+len-1, j);
	}
// 	printf("\n");
	for(int s=0, i=level+1; s<(len-2); s++, i++){
	    ret += mat[i][level] + mat[i][level+len-1];
// 	    printf(" (%d, %d) (%d, %d)", i, level, i, level+len-1);
	}
// 	printf("\n");
// 	printf("%d\n", ret);
    ans[sz++] = ret;
	recur(level+1, len-2);

}

int main(){
int n;
int line = 1;

	while(true){
	     scanf("%d",&n);
	     if(n == 0)
	        break;
	     for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++)
	            scanf("%d", &mat[i][j]);
	     sz = 0;
	     recur(0, n);
	     printf("Case %d:", line++);
	     for(int i=0; i<sz; i++)
	         printf(" %d", ans[i]);
	     printf("\n");
	}
	return 0;
}

