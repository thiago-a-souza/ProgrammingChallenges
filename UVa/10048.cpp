/* AUDIOPHOBIA - 17/04/2007 */
#include <iostream>

using namespace std;

#define MAX 100
#define INFINITY 3200000

int d[MAX][MAX], C;

void floydMinMax(){
register int i, j, k;
int maior;

	for(k=0; k<C; k++)
	   for(i=0; i<C; i++)
	      for(j=0; j<C; j++){
	      	  if(d[i][k]>d[k][j])
	      	     maior = d[i][k];
	      	  else
	      	     maior = d[k][j];
	      	  if(d[i][j]>maior){
	      	     d[i][j]=maior;
	      	     d[j][i]=maior;
	      	  }
	      }
}

void initialize(){
register int i, j;
	for(i=0; i<C; i++){
	   for(j=0; j<C; j++)
	       d[i][j]=INFINITY;
	   d[i][i]=0;
	}
}

int main(){
register int i;
int Q, S, a, b, c, caso;

	caso = 1;
	cin >> C >> Q >> S;
	while(C!=0 && Q!=0 && S!=0){
	     initialize();
	     if(caso>1)
	       cout << endl;
	     for(i=0; i<Q; i++){
	         cin >> a >> b >> c;
	         if(a!=b){
	            d[a-1][b-1]=c;
	            d[b-1][a-1]=c;
	         }
	     }
	     floydMinMax();
	     cout << "Case #" << caso << endl;
	     caso++;
	     for(i=0; i<S; i++){
	        cin >> a >> b;
	        if(d[a-1][b-1]!=INFINITY)
	           cout << d[a-1][b-1] << endl;
	        else
	           cout << "no path\n";
	     }
	     cin >> C >> Q >> S;
	}
}

