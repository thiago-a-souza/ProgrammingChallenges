#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main(){
int val;

	printf("PERFECTION OUTPUT\n");
	while(true){
	     scanf("%d",&val);
	     if(val == 0)
	        break;
	     int lim = val/2;
	  //   printf("sqrt = %d\n",lim);
	     int sum = 0;
	  //   printf("multiplos de %d\n ------------",val);
	     for(int i=1; i<=lim; i++)
	        if(val % i == 0){
	    //    printf("%d\n",i);
	           sum += i;
	        }
	    // printf("-----------------\n");
	    // printf("sum=%d\n",sum);
	     if(sum == val)
	        printf("%5d  PERFECT\n",val);
	     else if(sum > val)
	             printf("%5d  ABUNDANT\n",val);
	     else printf("%5d  DEFICIENT\n",val);

	     

	}
	printf("END OF OUTPUT\n");

}


