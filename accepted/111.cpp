/* History Grading - 07/06/2007 */
#include<iostream>
#include<cstdio>

using namespace std;

#define MAX 30

int LCS(int *a, int m, int *b, int n){
register int i, j;
int c[MAX][MAX];

	for(i=0; i<=m; i++)
	   for(j=0; j<=n; j++)
	      c[i][j]=0;
	for(i=1; i<=m; i++)
	   for(j=1; j<=n; j++)
	      if(a[i]==b[j])
	        c[i][j]=c[i-1][j-1]+1;
	      else
	          if(c[i-1][j]>=c[i][j-1])
	            c[i][j] = c[i-1][j];
	          else
	            c[i][j] = c[i][j-1];
	return c[m][n];
}

main(){
int a[MAX], b[MAX], m;
int tmp;
	cin >> m;
	for(int i=1; i<=m; i++){
	   cin >> tmp;
	   a[tmp] = i;
	}
	while((scanf("%d",&tmp))!=EOF){
		b[tmp]=1;
		for(int i=2; i<=m; i++){
		   cin >> tmp;
		   b[tmp] = i;
		}
		cout << LCS(a,m,b,m) << endl;
	}
return 0;
}



