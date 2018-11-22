#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>



#define MAX 500
#define INF 2147483647


using namespace std;



int main(){
int T, R, H;
int travel[MAX][MAX], rest[MAX][MAX], hotel[MAX][MAX];
int priceT[MAX], priceR[MAX], priceH[MAX];
int min, ansT, ansR, ansH;



	while(scanf("%d %d %d", &T, &R, &H) != EOF){
		  for(int i=0; i<T; i++){
		     scanf("%d", &priceT[i]);
		     for(int j=0; j<R; j++)
		         scanf("%d",&travel[i][j]);
		  }
		  
		  for(int i=0; i<R; i++){
		     scanf("%d", &priceR[i]);
		     for(int j=0; j<H; j++)
		        scanf("%d", &rest[i][j]);
		  }
		  
		  for(int i=0; i<H; i++){
		     scanf("%d", &priceH[i]);
		     for(int j=0; j<T; j++)
		         scanf("%d", &hotel[i][j]);
		  }
		  min = INF;
		  ansT = -1; ansR = -1; ansH = -1;
		  for(int tt=0; tt<T; tt++)
		     for(int rr=0; rr<R; rr++)
		        if(travel[tt][rr] == 0){
		           for(int hh=0; hh<H; hh++){
		               if(rest[rr][hh] == 0 && hotel[hh][tt] == 0 &&
		                  priceT[tt] + priceR[rr] + priceH[hh] < min){
		                  min = priceT[tt] + priceR[rr] + priceH[hh];
		                  ansT = tt;
		                  ansR = rr;
		                  ansH = hh;
		               }
		           }
		         }
		   if(ansT == -1 || ansR == -1 || ansH == -1)
		      printf("Don't get married!\n"); 
		   else
		      printf("%d %d %d:%d\n", ansT, ansR, ansH, min);
		  
	}
	return 0;
}
