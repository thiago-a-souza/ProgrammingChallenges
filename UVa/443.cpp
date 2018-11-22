#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 2000000000L

using namespace std;

int cmp(const void *a, const void *b){
        return ( *(long long*)a - *(long long*)b );
}

main(){
long long v[10000];
long long a, b, c, d;
long long sum = 0;
int count = 1, n;

        a = 1; b = 1; c = 1; d = 1;
		for(int i=0; i<31; i++){
		   b = 1;
		   for(int j=0; j<30; j++){
		      c = 1;
	          for(int k=0; k<30; k++){
	             d = 1;
	             for(int l=0; l<30; l++){
	                 if(a > MAX || b > MAX || c > MAX || d > MAX )
	                    break;
	                 sum = a * b;
	                 if(sum > MAX || sum < 0)
	                    break;
	                 sum = sum * c;
	                 if(sum > MAX || sum < 0)
	                    break;
	                 sum = sum * d;
	                 if(sum > MAX || sum < 0)
	                    break;
	                 
	                 v[count++] = sum;
	               d = d*7;
	             }
	             c = c*5;
	          }
	          b = b*3;
	       }
	       a = a*2;
	    }
		qsort(v, count, sizeof(long long), cmp);	 
     


    while(true){
         scanf("%d",&n);
         if( n == 0)
            break;

            
         if((n > 4 && n < 20) || n%100==11 || n%100==12 || n%100==13)
           printf("The %dth humble number is %llu.\n",n,v[n]);
         else {
           if(n%10 == 1)
              printf("The %dst humble number is %llu.\n",n,v[n]);
           else if(n%10 == 2)
                   printf("The %dnd humble number is %llu.\n",n,v[n]);
           else if(n%10 == 3)
                   printf("The %drd humble number is %llu.\n",n,v[n]);
           else 
             printf("The %dth humble number is %llu.\n",n,v[n]);
         }
    }	 
	
	

}

