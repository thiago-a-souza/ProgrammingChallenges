/* Optimal Array Multiplication Sequence - 27/06/2007 */
#include<iostream>
#include<climits>

using namespace std;

#define MAX 30
#define INF INT_MAX/2

int m[MAX][MAX], s[MAX][MAX], p[MAX], n;

void printPath(int i, int j){

	if(i==j)
	    cout << "A" << i;
	else{
	  cout << "(";
	  printPath(i,s[i][j]);
	  cout << " x ";
	  printPath(s[i][j]+1, j);
	  cout << ")";
	}

}

void mcm(int n){
register int i, j, l, k;
int q;
	for(i=1; i<=n; i++)
	   m[i][i] = 0;
	for(l=2; l<=n; l++)
	   for(i=1; i<=n-l+1; i++){
	      j = i+l-1;
	      m[i][j] = INF;
	      for(k=i; k<=j-1; k++){
	         q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
	         if(q < m[i][j]){
	           m[i][j] = q;
	           s[i][j] = k;
	         }
	      }
	   }
}

main(){
int i, cont=1;

	cin >> n;
	while(n!=0){
	     for(i=0; i<n; i++)
	        cin >> p[i] >> p[i+1];
	     mcm(n);
	     cout << "Case " << cont << ": ";
	     cont++;
	     printPath(1,n);
	     cout << endl;
	     cin >> n;
	}

}
