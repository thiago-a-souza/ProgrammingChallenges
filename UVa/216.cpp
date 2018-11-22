/* Getting in Line 05/08/2007 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>


using namespace std;

#define INF 320000000.0

int ans[10], n;
double minVal;
double dist[10][10];

typedef struct{
int x, y;
} TPoint;





void imprime(int *a){

    for(int i=0; i<n; i++)
       cout << a[i] << " ";
    cout << endl;
}

double check(int *a, int k){
double sum;

	sum = 0.0;
	for(int i=1; i<k; i++)
	   sum += dist[a[i-1]][a[i]];
	return sum;
}

void construct(int *a, int k, int *c, int *cand){
int in_perm[8];

    memset(in_perm, 0, sizeof(in_perm));
    for(int i=0; i<k; i++)
       in_perm[a[i]] = 1;
    *cand = 0;
    for(int i=0; i<n; i++)
       if(in_perm[i] == 0){
         c[*cand] = i;
         *cand = *cand + 1;
       }
}

void backtrack(int *a, int k){
int c[8], cand;

    if(k == n){
      double tmp = check(a,n);
       if(tmp < minVal){
         minVal = tmp;
         for(int i=0; i<=n; i++)
            ans[i] = a[i];
       }
    }
    else{
        construct(a, k, c, &cand);
        k++;
        for(int i=0; i<cand; i++){
            a[k-1] = c[i]; 
            if(check(a,k) > minVal)
              break;
            backtrack(a, k);
        }
    }
}

main(){
int a[8], x1, x2, ite=1;
TPoint point[10];


	while(true){
		scanf("%d",&n);
		if(n == 0)
		  break;
		for(int i=0; i<n; i++){
		   scanf("%d %d", &x1, &x2);
		   point[i].x = x1;
		   point[i].y = x2;
		}
		for(int i=0; i<n; i++)
		   for(int j=0; j<n; j++)
		      if(i == j)
		        dist[i][j] = INF;
		      else
		      dist[i][j] = sqrt((point[i].x - point[j].x)*(point[i].x - point[j].x) +
		      			    (point[i].y - point[j].y)*(point[i].y - point[j].y))+16.0;
		minVal = 2000000000.0;
		backtrack(a, 0);
		printf("**********************************************************\n");
		printf("Network #%d\n",ite); ite++;
		for(int i=0; i<n-1; i++){
		   printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
             point[ans[i]].x, point[ans[i]].y, point[ans[i+1]].x, point[ans[i+1]].y, dist[ans[i]][ans[i+1]]);
          }
   //       imprime(a);
		printf("Number of feet of cable required is %.2lf.\n",minVal);
	
	}


}

