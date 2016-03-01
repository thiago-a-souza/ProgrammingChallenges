/* Longest Palindrome */
#include <iostream>
using namespace std;

#define MAX 1001

int LCS(char *a, char *b){
register int i, j;
int m, n;
int c[MAX][MAX];

	m = strlen(a);
	n = strlen(b);
	for(i=0; i<m; i++)
	   for(j=0; j<n; j++)
	      c[i][j]=0;
	for(i=1; i<=m; i++)
	   for(j=1; j<=n; j++)
	      if(a[i-1]==b[j-1])
	        c[i][j]=c[i-1][j-1]+1;
	      else
	          if(c[i][j-1]>c[i-1][j])
	            c[i][j] = c[i][j-1];
	          else
	            c[i][j] = c[i-1][j];
	return c[m][n];
}

int main(){
char str[MAX], palim[MAX], tmp[2];
register int i, j, k;
int n;
	cin >> n;
	for(k=0; k<n; k++){
		if(k==0)
		cin.getline(tmp,2);
		cin.getline(str,MAX);
		for(i=0, j=strlen(str)-1; j>=0; i++, j--)
		   palim[i]=str[j];
		palim[i]='\0';
		cout << LCS(str,palim) << endl;
	}
	return 0;
}



