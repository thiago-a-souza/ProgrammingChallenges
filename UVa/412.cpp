#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 100

using namespace std;

int gcd(int a, int b){
      if( b == 0)
         return a;
    return gcd(b,a%b);
}

main(){
int n, possi, diffs;
int v[MAX];
double pi; 

		while(true){
		     scanf("%d",&n);
		     if(n == 0)
		        break;
		     for(int i=0; i<n; i++)
		        scanf("%d",&v[i]);

  		     possi = 0;
		     diffs = 0;

		     for(int i=0; i<n-1; i++)
		        for(int j=i+1; j<n; j++){
		            possi++;
		            if(gcd(v[i],v[j]) == 1)
		               diffs++;
		        }
		     if(diffs == 0)
		        printf("No estimate for this data set.\n");
		     else {
		        pi = sqrt((6.0*((double)possi))/((double)diffs));
		        printf("%.6lf\n",pi);
		     }  
		}

}

