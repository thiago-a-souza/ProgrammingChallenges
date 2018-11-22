/* Cutting Sticks - 31/07/2007 */
#include<iostream>
#include<cstdio>

using namespace std;

#define MAX 100
#define INF 3200000
int memo[MAX][MAX], cuts[MAX];


int cutting(int a, int b){
int q;
	if(memo[a][b]!=INF)
	  return memo[a][b];
	if(b-a==1||a==b){
	  memo[a][b]=0;
	}
	else{
	   for(int i=a; i<b-1; i++){
	      q = cutting(a,i+1)+cutting(i+1,b)+(cuts[b]-cuts[a]);
	      if(q<memo[a][b])
	        memo[a][b] = q;
	   }   
	}
	return memo[a][b];

}

main (){
int L, n;

	cin >> L;
	while(L!=0){
	     cin >> n;
	     cuts[0]=0;
	     for(int i=1; i<=n; i++)
	        scanf("%d",&cuts[i]);
	     cuts[n+1]=L;
	     for(int i=0; i<MAX; i++)
	        for(int j=0; j<MAX; j++)
	           memo[i][j]=INF;

	     printf("The minimum cutting is %d.\n",cutting(0,n+1));
	     scanf("%d",&L);
	}

 
}


