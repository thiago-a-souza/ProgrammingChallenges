#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(){
int tests;
int term1, term2, final, attendance, test1, test2, test3;
int aux, sum;
int index = 1;

	scanf("%d", &tests);
	while(tests--){
	      scanf("%d %d %d %d %d %d %d",&term1, &term2, &final, &attendance, 
	                                   &test1, &test2, &test3);
	      if(test1 < test2){
	         aux = test2;
	         test2 = test1;
	         test1 = aux;
	      }
	      
	      if(test2 < test3){
	         aux = test3;
	         test3 = test2;
	         test2 = aux;
	      }
	      
	      sum = term1 + term2 + final + attendance + (test1 + test2)/2;
	      printf("Case %d: ", index++);
	      if(sum >= 90)
	         printf("A\n");
	      else if(sum >= 80)
	              printf("B\n");
	      else if(sum >= 70)
	              printf("C\n");
	      else if(sum >= 60)
	              printf("D\n");
	      else printf("F\n");

	              
	         
	   
	
	}
}

