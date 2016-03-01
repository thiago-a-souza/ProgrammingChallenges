#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#define MAX_VAL 50002

using namespace std;



main(){
int i, j, n, m, sum, half;
int C[101], F[MAX_VAL];

		scanf("%d",&n);
		while(n--){
			scanf("%d",&m);
			
			sum = 0;
			for(i=0; i<m; i++){
			   cin >> C[i];
			   sum += C[i];
			}
			
			for(i=0; i<MAX_VAL; i++)
			    F[i] = 0;
			
			F[0] = 1;
			half = sum/2;
			
			for(i=0; i<m; i++){
			   if(C[i] > half)
			      continue;
			   for(j = (half-C[i]); j>=0; j--){
			       if(F[j] > 0)
			         F[j+C[i]] = 1;
			   }
			   if(F[half] > 0)
			      break;  
			}
			
			for(i=half; i>=0; i--)
			   if(F[i] > 0)
			      break;
  	        int tmp = sum - (2*i);
		    cout << tmp << endl;
  
			
			
		}

}

