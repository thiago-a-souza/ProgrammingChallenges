/* Continued Fractions - 17/11/2007 */
/* Category: Math */
#include <iostream>
#include <cstdio>



#define ff(i,v,n) for(int i=v; i<n; i++)
#define f(i,n) ff(i,0,n)


using namespace std;

void swap(int *a, int *b){
int x;
	x = *a;
	*a = *b;
	*b = x;
}

main(){
int num, den, pInt, tam;



	while(scanf("%d %d",&num,&den) == 2){
	     pInt = num/den;
	     num -= den*pInt;
	     printf("[%d;",pInt);
	     swap(&num, &den);
	     while(true){
	          pInt = num/den;
	          num -= den*pInt;
	          if(num != 0)
	            printf("%d,",pInt);
	          else{
	             printf("%d]\n",pInt);
	             break;
	          }
	          swap(&num, &den);
	     }
	}

}


