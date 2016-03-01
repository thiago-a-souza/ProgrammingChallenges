#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>


#define MAX 1000000

using namespace std;

int gcd(long long a, long long b){
      if( b == 0)
         return a;
    return gcd(b,a%b);
}


main(){
long long a, b, c, cont2;
int v1[MAX+1], v3[MAX+1];
int nn;


	  for(int i=0; i<MAX+1; i++) {
	     v1[i] = 0;
	     v3[i] = 0;
	  }


	for(long long k=1; k<=200000; k++){
	  for(long long n = 1; n<= 1000 ; n++){
	     for(long long m = n+1 ; m<= 1000; m++){
	         a = k*(m*m - n*n);
	         b = k*(2*m*n);
	         c = k*(m*m + n*n);
	         if(a > MAX || b > MAX || c > MAX )
	            break;
	         if((m%2 == 0 || n%2 == 0) && gcd(a,gcd(b,c)) == 1 )
	              v1[c]++;
	         
	         if(v3[a] <= 0 || v3[a] > c)
	            v3[a] = c;
	           
	            
	         if(v3[b] <= 0 || v3[b] > c)
	            v3[b] = c;
	            
	         if(v3[c] <= 0 || v3[c] > c)
	            v3[c] = c;
	     }
  	  }
	}
	
	     for(int i=1; i<MAX+1; i++)
	        v1[i] = v1[i] + v1[i-1];

	     while(scanf("%d",&nn) != EOF){
	          cont2 = 0;
	          for(int i=1; i<=nn; i++){
	              if(v3[i] <= 0 || v3[i] > nn){
	                 cont2++;
	              }
	              
	          }
	          printf("%d %llu\n",v1[nn], cont2);
	     }
	 
}