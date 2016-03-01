#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>

#define MAX 10100

using namespace std;

/*
Número de passos é crescente ou decrescente (ex. 1+2+2+1).
Partindo de 45 é possível chegar em 48 com 3 passos => 45 + (1+2+1).
Com base na tabela abaixo chegamos as funções:
 f(2n) = n(n+1) 
 f(2n+1) = (n+1)^2;

+-----------+------------------------+
|  passos   |   comprimento máximo   |
+-----------+------------------------+
|    0      |       0 (0)            |
|    1      |       1 (1)            |
|    2      |       2 (11)           |
|    3      |       4 (121)          |
|    4      |       6 (1221)         |
|    5      |       5 (12321)        |
+-----------+------------------------+
*/

main(){
int n, a, b;
int tmp, steps, ans;

	scanf("%d",&n);
	for(int i=0; i<n; i++){
	   scanf("%d %d",&a,&b);
	   if(a == b){
	      printf("0\n");
	      continue;
	   } 

	   steps = 0;
	   while(1){			
			tmp = steps*(steps+1);
			if(tmp+a >= b){
			   ans = 2*steps;
			   break;
		    }
//		    steps++;

			tmp = (steps+1)*(steps+1);
			if(tmp+a >= b){
			   ans = 2*steps + 1;
			   break;
			}
			steps++;

	   }
	   printf("%d\n",ans);
	   
	   
	   
	   
	}

}

