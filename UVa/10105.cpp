#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

using namespace std; 

/*
Formula para encontrar o coeficiente desejado: n!/Пn(i)!
*/

main(){
long long n, k, numerator, denominator;
long long fat, x[20];


		while(scanf("%llu %llu",&n,&k) != EOF){ 
			for(int i=0; i<k; i++)
			   scanf("%llu",&x[i]);
		    
		    if(n == 0 || n == 1 || k == 0 || k == 1){
		      printf("0\n");
		      continue;
		    }
		      
		   
	        numerator = 1;
			for(int i=1; i<=n; i++)   
			    numerator = numerator*i;
	   
		    denominator = 1;
		    for(int i=0; i<k; i++){
		       fat = 1;
		       if(x[i] > 0){
		          for(int j=1; j<=x[i]; j++)
		             fat = fat*j;
		       }
		       denominator = denominator*fat;
		    }
		    cout << numerator/denominator << endl;
	    }
	     
		
}

